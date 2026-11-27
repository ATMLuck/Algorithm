#include <cstddef>
#include <vector>
#include <type_traits>
#include <utility>
#include <cassert>

namespace atm::BIT
{   
    template<class T>
    class BIT
    {
        static_assert((std::is_integral_v<T>||std::is_floating_point_v<T>)&&!std::is_same_v<T, bool>,"Data type error");
        using size_type = std::size_t;
    private:

        // t_arr[0] 不使用，有效下标是 [1, size()]
        std::vector<T> t_arr;

        static constexpr size_type _lowbit(size_type n) noexcept {return n&(~n+1);}

        // O(n) 建树
        void _build(const std::vector<T> &arr)
        {
            t_arr.assign(arr.size()+1,T{});
            for(size_type i = 1;i<=arr.size();i++)
                t_arr[i] += arr[i-1];
            for(size_type i = 1;i<=arr.size();i++)
            {
                size_type j = i + _lowbit(i);
                if(j<=arr.size()) t_arr[j] += t_arr[i];
            }
        }

        // 单点加：把 num 加到 arr[index] 上，1-based
        void _add(size_type index, T num)
        {
            assert(index>=1 && index<=size());
            if(index == 0) return;
            const size_type n = size();
            for(;index<=n;index += _lowbit(index)) 
                t_arr[index] += num;
        }

        // 前缀和：arr[1] + ... + arr[n]
        T _sum(size_type n) const
        {
            assert(n<=size());
            if(n>size()) n = size();
            T ans{};
            for(;n>0;n-=_lowbit(n)) 
                ans += t_arr[n];
            return ans;
        }

        // 区间和：arr[l] + ... + arr[r]，闭区间，1-based
        T _range_sum(size_type l, size_type r) const
        {
            assert(1<=l && l<=r && r<=size());
            if(l>r) std::swap(l,r);
            if(l == 0) l = 1;
            if(r>size()) r = size();
            if(l>r) return T{};
            return _sum(r)-_sum(l-1);
        }
    public:
        BIT() = default;
        BIT(const std::vector<T> &arr) {_build(arr);}
        BIT(const BIT &other) = default;
        BIT(BIT &&other) = default;
        BIT &operator=(const BIT &other) = default;
        BIT &operator=(BIT &&other) = default;

        size_type size() const noexcept {return t_arr.empty()?0:t_arr.size()-1;}

        T operator[] (size_type n) const {return _range_sum(n,n);}

        void build(const std::vector<T> &arr)
        {
            _build(arr);
        }

        void add(size_type index, T num)
        {
            _add(index,num);
        }
        T sum(size_type n) const
        {
            return _sum(n);
        }
        T range_sum(size_type l, size_type r) const
        {
            return _range_sum(l,r);
        }
        void clear() noexcept
        {
            t_arr.clear();
        }
    };

}
