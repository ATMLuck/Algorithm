#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end(),[](string a,string b)->bool{return a+b>b+a;});
    for(int i = 0;i<n;i++) cout << arr[i];
    cout << endl;
    return 0;
}
