#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using LL=unsigned long long;
class peo
{
public:
    LL time;
    LL id;
};
int main()
{
    LL n;
    cin >> n;
    vector<peo> arr(n);
    for(LL i = 0;i<n;i++)
    {
        cin >> arr[i].time;
        arr[i].id = i+1;
    }
    sort(arr.begin(),arr.end(),[](peo a, peo b)->bool
                                                    {
                                                        if(a.time!=b.time) return a.time<b.time;
                                                        else return a.id<b.id;
                                                    });
    double ans;
    LL sum_time=0;
    for(int i = 0;i<n-1;i++) sum_time+=arr[i].time*(n-i-1);
    ans = (double)sum_time/(n);
    for(auto i:arr) cout << i.id << ' ';
    printf("\n%.2lf\n",ans);


    return 0;
}