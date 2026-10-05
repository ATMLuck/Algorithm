#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using LL=unsigned long long;
struct Work
{
    LL Di;
    LL Pi;
};

int main()
{
    LL n;
    scanf("%llu",&n);
    vector<Work> arr(n);
    for(LL i = 0ULL;i<n;i++) scanf("%llu %llu",&arr[i].Di,&arr[i].Pi);
    sort(arr.begin(),arr.end(),[](Work a,Work b)->bool{if(a.Di!=b.Di) return a.Di<b.Di;else return a.Pi>b.Pi;});
    priority_queue<LL, vector<LL>, greater<LL>> ans_t;
    LL ans = 0,t = 0;
    for(LL i = 0;i<n;i++)
    {
        if(t<arr[i].Di)
        {
            t++;
            ans_t.push(arr[i].Pi);
            ans += arr[i].Pi;
        }
        else if(arr[i].Pi > ans_t.top())
        {
            ans-=ans_t.top();
            ans_t.pop();
            ans+=arr[i].Pi;
            ans_t.push(arr[i].Pi);
        }
    }
    printf("%llu",ans);

    return 0;
}