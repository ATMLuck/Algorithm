#include "iostream"
using namespace std;
int list_sum(int n,int exc)
{
    if(n-exc==0) return 0;
    if(n-exc==1) return 1;
    int a = 0,b = 1,c,sum = 1;
    n = n-exc-1;
    while(n--)
    {
        c = a+b;
        a = b;
        b = c;
        sum +=c;
    }
    return sum;
}
int main()
{
    int a,n,m,x;
    cin >> a >> n >> m >> x;
    if(n<=3)
    {
        if(n==1) cout << a << endl;
        if(n==2) cout << a << endl;
        if(n==3) cout << 2*a << endl;
        return 0;
    }
    int base = ((m-2*a)-a*list_sum(n-1,4))/list_sum(n-1,3);
    int ans = 2*a+a*list_sum(x,4)+base*list_sum(x,3);
    cout << ans << endl;
    return 0;
}