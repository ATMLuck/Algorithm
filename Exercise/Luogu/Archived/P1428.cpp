#include "iostream"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    int* ans = new int[n];
    for(int i = 0;i <n;i++)
    {
        cin >> arr[i];
        int cnt = 0;
        for(int j = 0;j<i;j++) if(arr[j]<arr[i]) cnt++;
        ans[i] = cnt;
    }
    for(int i = 0;i<n;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}