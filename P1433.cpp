#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
const double INF = std::numeric_limits<double>::infinity();

using namespace std;
using ULL = unsigned long long;
struct point
{
    double x;
    double y;
    point(double X,double Y)
    {
        x = X;
        y = Y;
    }
    point()
    {
        x=0;
        y=0;
    }
};
double d(point a,point b)
{
    return sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2));
}
int main()
{
    int n;
    cin >> n;
    vector<point> arr(n+1);
    arr[0] = point(); 
    for(int i = 0;i<n;i++)
    {
        double x,y;
        cin >> x >> y;
        arr[i+1] = point(x,y);
    }
    vector<vector<double>> dp(1ULL<<n,vector<double> (n,INF));
    for(int i = 0;i<n;i++) dp[1ULL<<i][i] = d(arr[0],arr[i+1]);
    
    for(ULL s = 0ULL;s<1ULL<<n;s++)
    {
        for(int i = 0;i<n;i++)
        {
            if((s>>i)&1)
            {
                for(int j = 0;j<n;j++)
                {
                    if(!((s>>j)&1))
                    {
                        dp[s|(1ULL<<j)][j] = min(dp[s][i]+d(arr[i+1],
                            arr[j+1]),dp[s|(1ULL<<j)][j]);
                    }   
                }
            }
        }
    }
    double ans = INF;
    for(double vir:dp[(1ULL<<n)-1]) ans = min(ans,vir);
    printf("%.2lf",ans);
    return 0;
}