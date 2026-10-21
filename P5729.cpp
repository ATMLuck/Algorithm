#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int w,x,h;
    cin >> w >> x >> h;
    vector<vector<vector<int>>> arr(w+1,vector<vector<int>> (x+1,vector<int> (h+1,1)));
    int q,ans = w*x*h;
    cin >> q;
    while(q--)
    {
        int w1,w2,x1,x2,h1,h2;
        cin >> w1 >> x1 >> h1 >> w2 >> x2 >> h2;
        for(int i = w1;i<=w2;i++)
        {
            for(int j = x1;j<=x2;j++)
            {
                for(int k = h1;k<=h2;k++)
                {
                    if(arr[i][j][k]==1)
                    {
                        arr[i][j][k] = 0;
                        ans--;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}