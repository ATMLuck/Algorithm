#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int> (n+1,0));
    arr[0][1] = 1;
    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<=i+1;j++)
        {
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 1;j<=i+1;j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}