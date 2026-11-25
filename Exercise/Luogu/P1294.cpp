#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void DFS(vector<vector<int>> &map,int n,vector<bool> &dit,int &ans,int vir,int len)
{
    vector<int> next(0);
    for(int i = 0;i<n;i++)
        if(map[vir][i]!=0&&dit[i])
            next.push_back(i);
    if(!next.size()) {ans = max(ans,len);return;}
    for(int i :next)
    {
        dit[i] = false;
        DFS(map,n,dit,ans,i,len+map[vir][i]);
        dit[i] = true;
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> map(n,vector<int> (n,0));
    for(int i = 0;i<m;i++)
    {
        int a,b,l;
        cin >> a >> b >> l;
        a--;b--;
        map[a][b] = map[b][a] = l;
    }
    int ans = 0;
    vector<bool> dit(n,true);
    for(int i = 0;i<n;i++)
    {
        dit[i] = false;
        DFS(map,n,dit,ans,i,0);
        dit[i] = true;
    }
    cout << ans << endl;
    return 0;
}
