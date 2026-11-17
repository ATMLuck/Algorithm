#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n+2,vector<int> (n+2,0));
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
        {
            if(i==0)dp[i][j]=1;
            else if(j==0) dp[i][j]=dp[i-1][j+1];
            else dp[i][j] = dp[i-1][j+1] + dp[i][j-1];
        }
    cout << dp[n][0] << endl;
    return 0;
}
/*
dp[i][j]:未入栈数为i，已入栈数为j时的方案数
dp[n][0]

*/