#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> arr(10);
    for(int i = 0;i<10;i++)
    {
        cin >> arr[i];
    }
    int vir;
    cin >> vir;
    int ans = 0;
    for(int i : arr)
    {
        if(i<=vir+30) ans++;
    }
    cout << ans << endl;
    return 0;
}