#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct line
{
    int start;
    int end;
};
bool cmp(line a, line b)
{
    if(a.end!=b.end) return a.end<b.end;
    else return a.start > b.start;
}
int main()
{
    int n;
    cin >> n;
    vector<line> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i].start >> arr[i].end;
    sort(arr.begin(),arr.end(),cmp);
    int ans = 0,time = 0;
    for(auto vir:arr)
    {
        if(vir.start >=time)
        {
            ans++;
            time = vir.end;
        }
    }
    cout << ans << endl;

    return 0;
}