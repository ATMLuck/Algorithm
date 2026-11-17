#include <iostream>
#include <vector>
using namespace std;
int DFS(vector<vector<bool>> &arr,int vir_x,int vir_y,const int fx,const int fy)
{
    if(vir_x<=0||vir_x>=(int)arr.size()||vir_y<=0||vir_y>=(int)arr[0].size()) return 0;
    if(arr[vir_x][vir_y]) return 0;
    if(vir_x==fx&&vir_y==fy) return 1;

    arr[vir_x][vir_y] = true;
    int ans = 0;
    ans += DFS(arr, vir_x+1, vir_y, fx, fy);
    ans += DFS(arr, vir_x-1, vir_y, fx, fy);
    ans += DFS(arr, vir_x, vir_y+1, fx, fy);
    ans += DFS(arr, vir_x, vir_y-1, fx, fy);
    arr[vir_x][vir_y] = false;
    return ans;
}

int main()
{
    int N,M,T;
    cin >> N >> M >> T;
    vector<vector<bool>> arr(N+1,vector<bool> (M+1,false));
    int sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;
    while(T--)
    {
        int tx,ty;
        cin >> tx >> ty;
        arr[tx][ty] = true;
    }
    cout << DFS(arr,sx,sy,fx,fy) << endl;
    return 0;
}
/*
2 2 1
1 1 2 2
1 2

1
*/