#pragma once
#include <algorithm>
#include <cstddef>
#include <memory>
#include <algorithm>
namespace atm
{
    template<typename T, class Alloc = std::allocator<T>>
    class vector
    {
    private:
        using traits = std::allocator_traits<Alloc>;
        using size_type = std::size_t;
        T* _begin;
        T* _end;
        T* _cap;
        Alloc _alloc;
    public:
        vector()
        {
            try
            {
                _begin = traits::allocate(_alloc, 15);
                _end = _begin;
                _cap = _begin + 14;
            }
            catch(...)
            {
                traits::deallocate(_alloc,_begin,15);
                _begin = _end = _cap = nullptr;
                throw;
            }
        }
        explicit vector(const size_type n)
        {
            size_type alloc_size = std::min((size_type)15,n);
            try
            {
                _begin = traits::allocate(_alloc,alloc_size);
                _end = _begin + alloc_size;
                _cap = _begin;
            }
        }
    };
}