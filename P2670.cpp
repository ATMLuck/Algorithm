#include <iostream>
#include <vector>
using namespace std;
void tap(vector<vector<char>> &arr,int x,int y)
{
    if(arr[x][y]!='?') return;
    int vir = 0;
    if(x!=0&&y!=0) if(arr[x-1][y-1]=='*') vir++;
    if(x!=0) if(arr[x-1][y]=='*') vir++;
    if(x!=0&&y!=arr[0].size()-1) if(arr[x-1][y+1]=='*') vir++;
    if(y!=0) if(arr[x][y-1]=='*') vir++;
    if(y!=arr[0].size()-1) if(arr[x][y+1]=='*') vir++;
    if(x!=arr.size()-1&&y!=0) if(arr[x+1][y-1]=='*') vir++;
    if(x!=arr.size()-1) if(arr[x+1][y]=='*') vir++;
    if(x!=arr.size()-1&&y!=arr[0].size()-1) if(arr[x+1][y+1]=='*') vir++;
    arr[x][y]=vir;
}
int main()
{
    int x,y;
    cin >> x >> y;
    vector<vector<char>> arr(x,vector<char> (y));
    for(int i = 0;i<x;i++) for(int j = 0;j<y;j++) cin >> arr[i][j];
        
    for(int i = 0;i<x;i++) for(int j = 0;j<y;j++) tap(arr,i,j);
    for(int i = 0;i<x;i++) 
    {
        for(int j = 0;j<y;j++)
        {
            if(arr[i][j]=='*') cout << arr[i][j];
            else cout << (int)arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}