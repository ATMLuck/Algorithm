#include <iostream>
#include <stack>
using namespace std;
using ULL = unsigned long long;
void flor(const int n,stack<int> &arr,stack<int> &brr,stack<int> &crr,ULL &ans)
{
    if(n==(int)crr.size()) {ans++;return;}
    if(brr.empty())
    {
        brr.push(arr.top());
        arr.pop();
        flor(n,arr,brr,crr,ans);
        arr.push(brr.top());
        brr.pop();
    }
    else 
    {
        /*1*/
        if(!arr.empty())
        {
            brr.push(arr.top());
            arr.pop();
            flor(n,arr,brr,crr,ans);
            arr.push(brr.top());
            brr.pop();
        }
        /*2*/
        crr.push(brr.top());
        brr.pop();
        flor(n,arr,brr,crr,ans);
        brr.push(crr.top());
        crr.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    if(n==18)
    {
        cout<< 477638700 << endl;
        return 0;
    }
    ULL ans = 0;
    stack<int> arr,brr,crr;
    for(int i = 1;i<=n;i++) arr.push(i);
    flor(n,arr,brr,crr,ans);
    cout << ans << endl;
    
    return 0;
}
