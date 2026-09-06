#include "iostream"
#include "vector"
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++) cin >> arr[i];
    while(m--)
    {
        int q;
        cin >> q;
        cout << arr[q] << '\n';
    }
    return 0;
}