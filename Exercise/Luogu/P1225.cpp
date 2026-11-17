#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

//#include <bitset>

using ULL=unsigned long long;
using namespace std;
struct Pair
{
    ULL first;
    int second;
    vector<pair<int,int>> arr;
};
void setBit(ULL &vir, int index, int k)
{
    if(k==1)
        vir |= (1ULL << index);
    
    if(k==0)
        vir &= ~(1ULL << index);
}
bool sameBit(ULL x, int i, int j)
{
    return ((x >> i) & 1ULL) == ((x >> j) & 1ULL);
}
void swapBit(ULL &x, int i, int j)
{
    if (((x >> i) ^ (x >> j)) & 1ULL) {
        x ^= (1ULL << i) | (1ULL << j);
    }
}
void outPut(vector<pair<int,int>> &arr,int step)
{
    int tmp = 0;
    cout << step << endl;
    for(auto &p:arr)
    {
        tmp++;
        cout<<p.first+1<<p.second+1;
        if(tmp%2==0)
        {
            tmp=0;
            cout << endl;
        }
    }
}
void BFS(queue<Pair> &BFS_Q, vector<bool> &dist, ULL target, int &ans)
{
    while(!BFS_Q.empty())
    {
        int step = BFS_Q.front().second;
        ULL vir = BFS_Q.front().first;
        vector<pair<int,int>> arr = BFS_Q.front().arr;
        BFS_Q.pop();
        if(vir==target) {ans = step;outPut(arr,ans);return;}
        for(int i = 0;i<16;i++)
        {
            int next = i+1,down = i+4;
            if(i%4==3) next = 100;
            ULL vir1 = vir, vir2 = vir;
            if(next<16&&!sameBit(vir1,i,next))
            {
                swapBit(vir1,i,next);
                if(dist[vir1])
                {
                    vector<pair<int,int>> arr1 = arr;
                    arr1.push_back({i/4,i%4});
                    arr1.push_back({next/4,next%4});
                    BFS_Q.push({vir1,step+1,arr1});
                    dist[vir1] = false;
                }
            }
            if(down<16&&!sameBit(vir2,i,down))
            {
                swapBit(vir2,i,down);
                if(dist[vir2])
                {
                    vector<pair<int,int>> arr2 = arr;
                    arr2.push_back({i/4,i%4});
                    arr2.push_back({down/4,down%4});
                    BFS_Q.push({vir2,step+1,arr2});
                    dist[vir2] = false;
                }
            }
        }
    }
}
int GitC()
{
    char a;
    cin >> a;
    while(a<'0'||a>'1') cin >> a;
    return a-'0';
}
int main()
{
    ULL vir = 0,target = 0;
    for(int i=0,p=0;i<4;i++)
    {
        for(int j = 0;j<4;j++,p++)
        {
            int data = GitC();
            if(data==1) setBit(vir,p,1);
        }
        cin.get();
    }
    for(int i=0,p=0;i<4;i++)
    {
        for(int j = 0;j<4;j++,p++)
        {
            int data = GitC();
            if(data==1) setBit(target,p,1);
        }
        cin.get();
    }
    queue<Pair> BFS_Q;
    BFS_Q.push({vir,0,vector<pair<int,int>>(0)});
    int ans = -1;
    vector<bool> dist(1<<16,true);
    dist[vir] = false;
    BFS(BFS_Q,dist,target,ans);
    return 0;
}