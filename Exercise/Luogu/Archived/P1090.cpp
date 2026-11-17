#include <cstdio>
#include <queue>

using ULL=unsigned long long;
using namespace std;
int main()
{
    ULL n;
    scanf("%llu",&n);
    ULL data;
    priority_queue<ULL, vector<ULL>, greater<ULL>> arr;
    while(n--)
    {
        scanf("%llu",&data);
        arr.push(data);
    }
    ULL ans = 0;
    while(arr.size()!=1)
    {
        int a,b;
        a = arr.top();
        arr.pop();
        b = arr.top();
        arr.pop();
        ans+=a+b;
        arr.push(a+b);
    }
    printf("%llu",ans);
    return 0;
}