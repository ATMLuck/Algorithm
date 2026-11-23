#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <utility>
enum PointColor
{
    red,
    balck,
    white
};
using namespace std;
void BFS(const vector<vector<int>> &map,vector<int> &dist,int vir,int &ans)
{
    vector<int> ans_num = {0,0};
    queue<pair<int,int>> BFS_Q;
    BFS_Q.push({vir,balck});
    dist[vir] = balck;
    ans_num[balck]++;
    while(!BFS_Q.empty())
    {
        pair<int,int> p = BFS_Q.front();
        BFS_Q.pop();
        int next_color = (p.second==balck?red:balck);
        for(auto next_point:map[p.first])
        {
            if(dist[next_point] == p.second)
            {
                cout << "Impossible" << endl;
                exit(0);
            }
            if(dist[next_point] == white)
            {
                dist[next_point] = next_color;
                ans_num[next_color]++;
                BFS_Q.push({next_point,next_color});
            }
        }
    }
    ans+=(ans_num[red]<ans_num[balck]?ans_num[red]:ans_num[balck]);
}
int main()
{
    int n,m,ans=0;
    cin >> n >> m;
    vector<vector<int>> map(n,vector<int> (0));
    vector<int> dist(n,white);
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(int i = 0;i<n;i++)
    {
        if(dist[i]==white)
        {
            BFS(map,dist,i,ans);
        }
    }
    cout << ans << endl;

    return 0;
}