#include "iostream"
#include "vector"
#include "string"
using namespace std;
vector<int> add(const vector<int>& a,const vector<int>& b)
{
    vector<int> c(0);
    for(int i = 0;i<a.size();i++)
    {
        c.push_back(a[i]+b[i]);
    }
    for(int i = a.size();i<b.size();i++)
    {
        c.push_back(b[i]);
    }
    int vir = 0;
    for(int i = 0;i<c.size();i++)
    {
        c[i]+=vir;
        vir = c[i]/10;
        c[i] %=10;
    }
    if(vir) c.push_back(vir);
    return c;
}
int main()
{
    int n ;
    cin >> n;
    if(n==1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if(n==2)
    {
        cout << 2 << endl;
        return 0;
    }
    n-=2;
    vector<int> a = {1},b = {2};
    while(n--)
    {
        a = add(a,b);
        swap(a,b);
    }
    string ans = "";
    for(int i =b.size()-1;i>=0;i--) ans += b[i]+'0';
    cout <<ans << endl;
    return 0;
}