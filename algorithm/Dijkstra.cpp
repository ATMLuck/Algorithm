#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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
    priority_queue<pair<Poit,Edge>,vector<pair<Poit,Edge>>,greater<pair<Poit,Edge>>> Que;
    vector<int> Dis_A(6,INF); 
    vector<bool> dit(6,false);
    Que.push({A,0});
    while(!Que.empty())
    {
        auto vir = Que.top();
        Que.pop();
        if(dit[vir.first]) continue;
        for(auto next:Graph[vir.first])
        {
            if(dit[next.first]) continue;
            Que.push(next);
            Dis_A[next.first] = Dis_A[next.first]<next.second?Dis_A[next.first]:next.second;
            
        }
    }
}