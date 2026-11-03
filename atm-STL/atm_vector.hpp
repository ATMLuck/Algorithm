#pragma once
#include <memory>
#include <utility>
namespace atm
{
    template<typename T>
    class vector
    {
    public:
        
    private:
        T* _begin;
        T* _end;
        T* _cap;
        std::allocator<T> _alloc;
    };
}