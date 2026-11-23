#include <iostream>
#include <vector>
#include <algorithm>
#define INF (1<<20)

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> map(n+1,vector<int> (n+1,0));
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            cin >> map[i][j];
    vector<vector<int>> dp(1<<n,vector<int> (n+1,INF));
    dp[1][1] = 0;
    for(int i = 0;i<=(1<<n)-1;i++)
        for(int j = 1;j<=n;j++)
            if((i&(1<<(j-1)))==0)
                for(int k = 1;k<=n;k++)
                    if(i&(1<<(k-1)))
                        dp[i|(1<<(j-1))][j]=min(dp[i|(1<<(j-1))][j],dp[i][k] + map[k][j]);
    int ans=INF;
    for(int i=2;i<=n;i++)
        ans=min(ans,dp[(1<<n)-1][i] + map[i][1]);
    cout << ans << endl;
            
    return 0;
}