#include "iostream"
#include "vector"
#include <unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;

    vector<unordered_map<int,int>> arr(n+1);
    while(m--)
    {
        int work;
        cin >> work;
        if(work==1)
        {
            int i,j,k;
            cin >> i >> j >> k;
            arr[i][j] = k;
        }
        else
        {
            int i,j;
            cin >> i >> j;
            cout << arr[i][j] << "\n";
        }
    }
    return 0;
}