#include <queue>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void BFS(vector<int> &Ans,queue<pair<string,int>> &BFS_Q,int source_size)
{
    while(!BFS_Q.empty())
    {
        string num = BFS_Q.front().first;
        int step = BFS_Q.front().second;
        int size = num.size();
        BFS_Q.pop();
        //swap
        for(int i = 0;i<size;i++)
        {
            for(int j = i+1;j<size;j++)
            {
                if(num[i]!=num[j])
                {
                    string vir = num;
                    swap(vir[i],vir[j]);
                    if(Ans[stoi(vir)]!=-1) continue;
                    BFS_Q.push({vir,step+1});
                    Ans[stoi(vir)] = step+1;
                }
            }
        }
        //erase
        if(size>1)
        {
            for(int i = 0;i<size;i++)
            {
                string vir = num;
                vir.erase(vir.begin()+i);
                if(Ans[stoi(vir)]!=-1) continue;
                BFS_Q.push({vir,step+1});
                Ans[stoi(vir)] = step+1;
            }
        }
        //add
        if(size<source_size)
        {
            for(int i = 1;i<size;i++)
            {
                char a = num[i-1],b = num[i];
                for(char j = a+1;j<b;j++)
                {
                    string vir = num;
                    vir.insert(i,1,j);
                    if(Ans[stoi(vir)]!=-1) continue;
                    BFS_Q.push({vir,step+1});
                    Ans[stoi(vir)] = step+1;
                }
            }
        }
    }
}
int main()
{
    string num;
    int q;

    cin >> num >> q;
    vector<int> Ans(100000,-1);
    Ans[stoi(num)] = 0;
    queue<pair<string,int>> BFS_Q;
    BFS_Q.push({num,0});
    BFS(Ans,BFS_Q,num.size());
    queue<int> output;
    while(q--)
    {
        string tmp;
        cin >> tmp;
        if(Ans[stoi(tmp)]!=-1) output.push(Ans[stoi(tmp)]);
        else output.push(-1);
    }
    while(!output.empty()){cout << output.front()<<endl;output.pop();}
    
    return 0;
}