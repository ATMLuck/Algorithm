#pragma once
#include <cstddef>
#include <ctime>
#include <memory>
#include <stdexcept>
#include <utility>
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
        friend void _swap(vector &a, vector &b)
        {
            std::swap(a._begin,b._begin);
            std::swap(a._end,b._end);
            std::swap(a._cap,b._cap);
            std::swap(a._alloc,b._alloc);
        }
    public:
        vector()
        {
            _begin = traits::allocate(_alloc, _default_size);
            _end = _begin;
            _cap = _begin + _default_size;
        }
        explicit vector(const size_type n,const T& _default_value = T())
        {
            size_type alloc_size = n+_default_size;
            size_type max_size = traits::max_size(_alloc);
            if(n + _default_size < n || n + _default_size > max_size)
            {
                throw std::length_error("atm::vector: size too large");
            }

            _begin = traits::allocate(_alloc,alloc_size);
            
            try
            {
                _construct(_begin,_begin+n,_default_value);
                _end = _begin + n;
                _cap = _begin + alloc_size;
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
            size_type capacity = other.capacity();
            _begin = traits::allocate(_alloc,capacity);
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
                _cap = _begin+capacity;
            }
            catch(...)
            {
                while(tmp!=_begin)
                {
                    --tmp;
                    traits::destroy(_alloc,tmp);
                }
                traits::deallocate(_alloc,_begin,capacity);
                _begin=_end=_cap=nullptr;
                throw;
            }
        }
        vector(vector&& other) noexcept : _alloc(std::move(other._alloc))
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
    };
}