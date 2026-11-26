#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
using Edge = int;
enum Poit
{
    A,B,C,
    D,E,F,
};
vector<vector<pair<Poit,Edge>>> Graph = 
{
    {{C,5},{D,7}},
    {{C,9},{F,2}},
    {{D,3},{E,8}},
    {{A,7}},
    {{F,10},{B,7},{D,1}},
    {{A,17}}
};
int main()
{
    priority_queue<pair<Edge,Poit>,vector<pair<Edge,Poit>>,greater<pair<Edge,Poit>>> Que;
    vector<int> Dis_A(6,INF); 
    Dis_A[A] = 0;
    vector<bool> dit(6,false);
    Que.push({0,A});
    while(!Que.empty())
    {
        auto vir = Que.top();
        Que.pop();
        if(dit[vir.second]) continue;
        dit[vir.second] = true;
        for(auto next:Graph[vir.second])
        {
            // Dis_A[next.first] = min(Dis_A[next.first],Dis_A[vir.second]+next.second);
            // Que.push({next.second,next.first});
            int candidate = Dis_A[vir.second] + next.second;
            if (candidate < Dis_A[next.first]) {
                Dis_A[next.first] = candidate;
                Que.push({candidate, next.first});
            }
        }
    }
    for(auto p:Dis_A) cout << p << ' ';
    cout << '\n';
}