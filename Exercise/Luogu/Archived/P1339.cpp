#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
const int INF=INT_MAX;
using namespace std;
using dis=int;
using point=int;
int main()
{
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<point,dis>>> map(n+1,vector<pair<point,dis>> (0));
    vector<bool> dist(n+1,false);
    for(int i = 0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        map[u].push_back(pair<point,dis>({v,w}));
        map[v].push_back(pair<point,dis>({u,w}));
    }
    vector<pair<dis,point>> Dijkstra(n+1,pair<dis,point>(INF,-1));
    priority_queue<pair<dis,point>,vector<pair<dis,point>>,greater<pair<dis,point>>> qu;
    Dijkstra[s] = {0,s};
    qu.push({0,s});
    while(!qu.empty())
    {
        if(dist[qu.top().second]) {qu.pop();continue;}
        pair<dis,point> vir = qu.top();
        qu.pop();
        dist[vir.second] = true;
        for(auto p:map[vir.second])
        {
            if(dist[p.first]) continue;
            if(p.second+vir.first<Dijkstra[p.first].first)
            {
                Dijkstra[p.first].first = p.second+vir.first;
                Dijkstra[p.first].second = vir.second;
                qu.push({Dijkstra[p.first].first,p.first});
            }
        }
        if(vir.second == t) break;
    }
    cout <<Dijkstra[t].first << endl;
    return 0;
}