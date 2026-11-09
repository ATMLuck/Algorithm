#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
struct Apple
{
    int hight;
    int value;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s,a,b,hight;
    cin >> n >> s >> a >> b;
    hight = a+b;
    vector<Apple> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].hight >> arr[i].value;
    }    
    sort(arr.begin(),arr.end(),[](Apple a,Apple b)->bool{return a.value<b.value;});
    int ans = 0,sum = 0;
    for(int i = 0;i<(int)arr.size();i++) 
    {
        if(sum+arr[i].value<=s&&arr[i].hight<=hight) 
        {
            sum+=arr[i].value;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}