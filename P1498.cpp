#include <iostream>
#include <vector>

using namespace std;
void work(vector<vector<char>> &arr,int &h,int &l,int &n)
{
    if(n<=1) return;
    vector<vector<char>> brr(h+1,vector<char> (l+1,' '));
    for(int i = 0;i<=h;i++)
    {
        for(int j = 0;j<=l;j++)
        {
            brr[i][j] = arr[i][j];
            arr[i][j] = ' ';
        } 
    }
    int ml = l/2;
    int nh = 2*h+1,nl = 2*l+1;
    for(int i = 0;i<=h;i++)
    {
        for(int j = 0;j<=l;j++)
        {
            arr[h+1+i][j] = brr[i][j];
            arr[h+1+i][l+1+j] = brr[i][j];
            arr[i][ml+1+j] = brr[i][j];
        }
    }
    n--;
    work(arr,nh,nl,n);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(1<<n,vector<char> (2<<n,' '));
    {
        arr[0][0] = ' ';
        arr[0][1] = '/';
        arr[0][2] = '\\';
        arr[0][3] = ' ';
        arr[1][0] = '/';
        arr[1][1] = '_';
        arr[1][2] = '_';
        arr[1][3] = '\\';
    }
    int h=1,l=3;
    work(arr,h,l,n);
    for(int i = 0;i<(int)arr.size();i++)
    {
        for(int j = 0;j<(int)arr[0].size();j++) cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}
/*

**|--|**
**|--|**
|--||--|
|--||--|


*/