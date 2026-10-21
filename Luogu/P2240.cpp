#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class cap
{
public:
    int m;
    int v;
    double step;
};
int main()
{
    int n,t;
    cin >> n >> t;
    vector<cap> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].m >> arr[i].v;
        arr[i].step = (double)arr[i].v/arr[i].m;
    }
    sort(arr.begin(),arr.end(),[](cap a, cap b)->bool {return a.step>b.step;});
    double ans = 0.0;
    for(cap vir:arr)
    {
        if(t>=vir.m)
        {
            t-=vir.m;
            ans +=vir.v;
        }
        else 
        {
            ans += t*vir.step;
            break;
        }
    }
    printf("%.2lf\n",ans);

    return 0;
}