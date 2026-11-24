#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int n,m,ans=0;
void DP(const vector<int> &arr)
{
    int sum_w = 0;
    for(int v : arr) sum_w+=v;
    vector<bool> dp(sum_w+1,false);
    dp[0] = true;
    for(int vir:arr)
        for(int w = sum_w;w>=0;w--) 
            if(w-vir>=0) dp[w] = (dp[w]||dp[w-vir]);
    int ans_t = 0;
    for(int vir = 1;vir<=sum_w;vir++)
        if(dp[vir]) ans_t++;
    ans=(ans>ans_t?ans:ans_t);
}
void DFS(vector<int> &arr,vector<bool> &dict,int deep,int index)
{
    if(deep<m)
        for(int i = index+1;i<n;i++)
        {
            dict[i] = false;
            DFS(arr,dict,deep+1,i); 
            dict[i] = true;
        }
    else
    {
        vector<int> select(0);
        for(int i = 0;i<n;i++)
            if(dict[i]) select.push_back(arr[i]);
        DP(select);
    }
}
int main()
{
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    vector<bool> dict(n,true);
    DFS(arr,dict,0,-1);
    cout << ans << endl;
    return 0;
}