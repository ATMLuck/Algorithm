#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for(int i = 1;i<=n;i++) cin >> arr[i];
    for(int i = 1;i<n;i++) arr[i]= (arr[i+1]-arr[i])>=0?(arr[i+1]-arr[i]):(arr[i]-arr[i+1]);
    sort(arr+1,arr+n);
    for(int i = 1;i<n;i++)
    {
        if(arr[i]!=i) 
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}