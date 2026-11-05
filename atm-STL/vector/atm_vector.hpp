#pragma once
#include <memory>
namespace atm
{
    template<typename T, class Alloc = std::allocator<T>>
    class vector
    {
    private:
        using traits = std::allocator_traits<Alloc>;
        T* _begin;
        T* _end;
        T* _cap;
        Alloc _alloc;
    public:
        
    };
}