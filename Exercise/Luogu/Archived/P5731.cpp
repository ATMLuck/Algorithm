#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int flag[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void step(pair<int,int> &it,int flags)
{
    it.first+=flag[flags][0];
    it.second+=flag[flags][1];
}
void output(int ans)
{
    cout << setw(3) << ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int> (n,-1));
    int flags = 0;
    pair<int,int> it = {0,0};
    for(int i = 1;i<=n*n;i++)
    {
        if(it.first>=0&&it.first<n&&it.second>=0&&it.second<n&&arr[it.first][it.second]==-1) 
            arr[it.first][it.second] = i; 
        else 
        {
            step(it,(flags+2)%4);
            flags++;
            flags%=4;
            i--;
        }
        step(it,flags);
    }
    for(auto a:arr)
    {
        for(auto b:a) output(b);
        cout << '\n';
    }
    return 0;
}