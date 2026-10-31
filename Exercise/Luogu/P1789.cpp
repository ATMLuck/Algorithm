#include <iostream>
#include <vector>
using namespace std;
void huoba(int x, int y, vector<vector<bool>> &arr, int n)
{
    arr[x][y] = false;
    if(x-2>=0) arr[x-2][y] = false;
    if(x-1>=0) arr[x-1][y] = false;
    if(x+1<n) arr[x+1][y] = false;
    if(x+2<n) arr[x+2][y] = false;
    if(y-2>=0) arr[x][y-2] = false;
    if(y-1>=0) arr[x][y-1] = false;
    if(y+1<n) arr[x][y+1] = false;
    if(y+2<n) arr[x][y+2] = false;
    if(x-1>=0&&y-1>=0) arr[x-1][y-1] = false;
    if(x+1<n&&y-1>=0) arr[x+1][y-1] = false;
    if(x-1>=0&&y+1<n) arr[x-1][y+1] = false;
    if(x+1<n&&y+1<n) arr[x+1][y+1] = false; 
}
void yinshi(int x, int y, vector<vector<bool>> &arr, int n)
{
    for(int i = -2;i<=2;i++)
    {
        for(int j = -2;j<=2;j++)
        {
            if(x+i>=0&&x+i<n&&y+j>=0&&y+j<n) arr[x+i][y+j] =false;
        }
    }
}
int ans(vector<vector<bool>> &arr, int n)
{
    int ANS = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]) ANS++;
        }
    }
    return ANS;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<bool>> arr(n,vector<bool> (n,true));
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        huoba(x-1,y-1,arr,n);
    } 
    while(k--)
    {
        int x,y;
        cin >> x >> y;
        yinshi(x-1,y-1,arr,n);
    }
    cout << ans(arr,n) << endl;

    return 0;
}