#include "iostream"
using namespace std;
int main()
{
    int n;
    double ans = 0.0;
    cin >> n;
    if(n>400)
    {
        ans += 150*0.4463;
        ans += 250*0.4663;
        ans += (n-400)*0.5663;
    }
    else if(n>150)
    {
        ans += 150*0.4463;
        ans += (n-150)*0.4663;
    }
    else
    {
        ans += n*0.4463;
    }
    printf("%.1lf",ans);
    
    return 0;
}