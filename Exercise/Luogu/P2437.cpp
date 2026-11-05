#include <iostream>
#include <vector>
#include <utility>
#define endl '\n'
using LL=unsigned long long;
using namespace std;
vector<int> add(vector<int> &a,vector<int> &b)
{
    if(a.size()>b.size()) swap(a,b);
    int size=b.size();
    vector<int> ans(size,0);
    for(int i = 0;i<size;i++)
    {
        if(i<(int)a.size()) ans[i] = a[i]+b[i];
        else ans[i]=b[i];
    }
    for(int i = 0;i<size;i++)
    {
        int res = ans[i]/10;
        if(res!=0)
        {
            if(i==size-1) ans.push_back(res);
            else ans[i+1]+=res;
        }
        ans[i]%=10;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL a,b;
    cin >> a >> b;
    int tmp = b-a-1;
    if(tmp<=0) 
    {
        cout << 1 << endl;
        return 0;
    }
    vector<int> i={1},j={1};
    while(tmp--)
    {
        i=add(i,j);
        swap(i,j);
    }
    for(int k = j.size()-1;k>=0;k--) cout << j[k];
    cout << endl;

    return 0;
}