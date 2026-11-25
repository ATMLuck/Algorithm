#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>
#include <new>
#include <iterator>
#include <type_traits>
namespace atm
{
    template<typename T, class Alloc = std::allocator<T>>
    class vector
    {
    public:
        using size_type = std::size_t;
        using value_type = T;
        using allocator_type = Alloc;
    private:
        using traits = std::allocator_traits<Alloc>;
        
        T* _begin = nullptr;
        T* _end = nullptr;
        T* _cap = nullptr;
        Alloc _alloc;
        static constexpr size_type _default_size = 15;

        void _construct(T* _head, T* _tail,const T& _value)
        {
            T* tmp = _head;
            try
            {
                while(tmp!=_tail)
                {
                    traits::construct(_alloc,tmp,_value);
                    tmp++;
                }
            }
            catch(...)
            {
                while(tmp!=_head)
                {
                    --tmp;
                    traits::destroy(_alloc,tmp);
                }
                throw;
            }
        }
        void _destroy_all()
        {
            T* tmp = _begin;
            while(tmp!=_end)
            {   
                traits::destroy(_alloc,tmp);
                tmp++;
            }
        }
        friend void _swap(vector &a, vector &b) noexcept(std::is_nothrow_swappable_v<Alloc>)
        {
            using std::swap;
            swap(a._begin,b._begin);
            swap(a._end,b._end);
            swap(a._cap,b._cap);
            swap(a._alloc,b._alloc);
        }
        bool _check_n(size_type n) const noexcept
        {
            return static_cast<size_type>(_cap-_end)>=n;
        }
        T* _migrate(T* first, T* last, T* dst)
        {
            T* cur = dst;
            try
            {
                
                for(;first!=last;first++,cur++)
                {
                    if constexpr (std::is_nothrow_move_constructible_v<T> ||
                            !std::is_copy_constructible_v<T>)
                    {
                        traits::construct(_alloc,cur,std::move(*first));
                    }
                    else
                    {
                        traits::construct(_alloc,cur,*first);
                    }
                }
            }
            catch(...)
            {
                while(cur!=dst){cur--;traits::destroy(_alloc,cur);}
                throw;
            }
            return cur;
            
        }

        // void _realloc()
        // {
        //     size_type new_capacity_size = this->capacity()>0?2*capacity():15;
        //     if(new_capacity_size>traits::max_size(_alloc)) new_capacity_size = traits::max_size(_alloc);
        //     T* new_begin = traits::allocate(_alloc,new_capacity_size);
        //     T* new_capacity = new_begin+new_capacity_size;
        //     T* new_end = nullptr;
        //     try
        //     {
        //         new_end = _migrate(_begin, _end, new_begin);
        //     }
        //     catch(...)
        //     {
        //         traits::deallocate(_alloc,new_begin,new_capacity_size);
        //         throw;
        //     }
        //     for(T* i= _begin;i!=_end;i++)
        //     {
        //         traits::destroy(_alloc,i);
        //     }
        //     if(_begin!=nullptr) traits::deallocate(_alloc,_begin,capacity());
        //     _begin = new_begin;
        //     _end = new_end;
        //     _cap = new_capacity;
        // }
        template<class U>
        void _append(U&& value)
        {
            traits::construct(_alloc,_end,std::forward<U>(value));
            ++_end;
        }
        template<class U>
        void _realloc_append(U&& value)
        {
            size_type max_size = traits::max_size(_alloc);
            if(max_size - this->capacity()<1) throw std::length_error("atm::vector: size too large");
            size_type new_capacity_size;
            if(this->capacity()==0) new_capacity_size = _default_size;
            else if(this->capacity()>max_size/2) new_capacity_size = max_size;
            else new_capacity_size = 2*this->capacity();
            T* new_begin = traits::allocate(_alloc,new_capacity_size);
            T* new_capacity = new_begin+new_capacity_size;
            T* new_end = nullptr;
            try
            {
                traits::construct(_alloc,new_begin+(_end-_begin),std::forward<U>(value));
            }
            catch(...)
            {
                traits::deallocate(_alloc,new_begin,new_capacity_size);
                throw;
            }
            try
            {
                new_end = _migrate(_begin, _end, new_begin)+1;
            }
            catch(...)
            {
                traits::destroy(_alloc,new_begin+(_end-_begin));
                traits::deallocate(_alloc,new_begin,new_capacity_size);
                throw;
            }
            for(T* i= _begin;i!=_end;i++)
            {
                traits::destroy(_alloc,i);
            }
            if(_begin!=nullptr) traits::deallocate(_alloc,_begin,capacity());
            _begin = new_begin;
            _end = new_end;
            _cap = new_capacity;
            
        }
    public:
        vector() noexcept(std::is_nothrow_default_constructible_v<Alloc>) = default;
        explicit vector(const size_type n,const T& _default_value = T())
        {
            size_type alloc_size = n;
            size_type max_size = traits::max_size(_alloc);
            if(n> max_size)
            {
                throw std::length_error("atm::vector: size too large");
            }

            _begin = traits::allocate(_alloc,alloc_size);
            
            try
            {
                _construct(_begin,_begin+n,_default_value);
                _end = _begin + n;
                _cap = _end;
            }
            catch(...)
            {
                traits::deallocate(_alloc,_begin,alloc_size);
                _begin=_end=_cap=nullptr;
                throw;
            }
        }
        vector(const vector& other)
        :_alloc(traits::select_on_container_copy_construction(other._alloc))
        {
            size_type size = other.size();
            if(size==0)
            {
                _begin = _end = _cap = nullptr;
            }
            else
            {
                _begin = traits::allocate(_alloc,size);
                const T* tmp_other = other.begin();
                T* tmp = _begin;

                try
                {
                    while(tmp_other!=other.end())
                    {
                        traits::construct(_alloc,tmp,*tmp_other);
                        tmp++;
                        tmp_other++;
                    }
                    _end = _begin+size;
                    _cap = _end;
                }
                catch(...)
                {
                    while(tmp!=_begin)
                    {
                        --tmp;
                        traits::destroy(_alloc,tmp);
                    }
                    traits::deallocate(_alloc,_begin,size);
                    _begin=_end=_cap=nullptr;
                    throw;
                }
            }
        }
        vector(vector&& other) noexcept(std::is_nothrow_move_constructible_v<Alloc>)
        : _alloc(std::move(other._alloc))
        {
            _begin = other._begin;
            _end = other._end;
            _cap = other._cap;
            other._begin = other._end = other._cap = nullptr;
        }
        ~vector()
        {
            _destroy_all();
            if(_begin!=nullptr) traits::deallocate(_alloc,_begin,_cap-_begin);
        }
        vector& operator=(vector other)
        {
            _swap(*this,other);
            return *this;
        }

        size_type size() const noexcept {return _end-_begin;}
        size_type capacity() const noexcept {return _cap-_begin;}
        const T* begin() const noexcept {return _begin;}
        T* begin() noexcept {return _begin;}
        const T* end() const noexcept {return _end;}
        T* end() noexcept {return _end;}
        const T* cap() const noexcept {return _cap;}
        T* cap() noexcept {return _cap;}

        void push_back(const T& value)
        {
            if(_check_n(1)) _append(value);
            else _realloc_append(value);
            
        }
        void push_back(T&& value)
        {
            if(_check_n(1)) _append(std::move(value));
            else _realloc_append(std::move(value));
        }

        
        
    };
}