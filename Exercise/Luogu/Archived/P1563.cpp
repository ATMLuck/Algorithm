#include "bits/stdc++.h"
using namespace std;
class Node
{
public:
    bool for_to;
    string name;
};
int work(int p,int n)
{
    p%=n;
    if(p<0) p+=n;
    return p;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<Node> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i].for_to >> arr[i].name;
    int p = 0;
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a==arr[p].for_to) p-=b;
        else p+=b;
        p = work(p,n);
    }
    cout << arr[p].name << endl;
    return 0;
}