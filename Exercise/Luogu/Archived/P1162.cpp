#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class par
{
public:
    int x;
    int y;
    par(int X,int Y)
    {
        x=X;
        y=Y;
    }
};
void BFS(vector<vector<int>> &arr,vector<vector<bool>> &brr,queue<par> &ton)
{
    int x = ton.front().x,y = ton.front().y,size = arr.size();
    ton.pop();
    if(x<0||y<0||x>=size||y>=size) return;
    if(brr[x][y]||arr[x][y]==1) return;
    arr[x][y] = 3;
    brr[x][y] = true;
    ton.push(par(x+1,y));
    ton.push(par(x-1,y));
    ton.push(par(x,y+1));
    ton.push(par(x,y-1));
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n+2,vector<int> (n+2,0));
    vector<vector<bool>> brr(n+2,vector<bool> (n+2,false));
    for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) cin >> arr[i][j];
    queue<par> ton;
    ton.push(par(0,0));
    while(!ton.empty()) BFS(arr,brr,ton);
    for(int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=n;j++)
        {
            if(arr[i][j]==3) cout << 0 <<' ';
            else if(arr[i][j]==1) cout << 1 << ' ';
            else if(arr[i][j]==0) cout << 2 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
6
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1

0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 2 2 1
1 1 2 2 2 1
1 2 2 2 2 1
1 1 1 1 1 1

*/