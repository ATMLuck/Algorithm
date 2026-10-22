#include <iostream>
#include <vector>
#include <string>

using namespace std;
string func(int mode,string a,string b)
{
    int ia = stoi(a);
    int ib = stoi(b);
    int ans;

    if(mode == 0) ans = ia+ib;
    else if(mode == 1) ans = ia-ib;
    else ans = ia*ib;

    string _ans = "",tmp = "";
    if(ans<0)
    {
        tmp+="-";
        ans = -ans;
    }

    while(ans!=0)
    {
        _ans = (char)(ans%10+'0')+_ans;
        ans /= 10;
    }
    return tmp+_ans;
} 
void work(int mode,string a,string b)
{
    string ans = a;
    if(mode==0) ans+='+';
    else if(mode==1) ans+='-';
    else ans+='*';
    ans=ans+b+'='+func(mode,a,b);
    cout << ans << endl;
    cout << ans.size() << '\n';
}
int main()
{
    int n;
    cin >> n;
    int mode = 0;
    while(n--)
    {
        string a,b,c;
        cin >> a;
        if(a=="a"||a=="b"||a=="c")
        {
            if(a == "a") mode = 0;
            else if(a=="b") mode = 1;
            else mode = 2;
            cin >> b >> c;
            work(mode,b,c);
        }
        else
        {
            cin >> b;
            work(mode,a,b);
        }
    }
    return 0;
}