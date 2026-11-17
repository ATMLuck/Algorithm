#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_set<int> brr,isfand;
    for(int i = 0;i<n;i++)
    {
        int data;
        cin >> data;
        arr[i] = data;
        brr.insert(data);
    }
    sort(arr.begin(),arr.end(),[](int a,int b)->bool {return a>b;});
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            int data = arr[i]+arr[j];
            if(data>arr[0]) continue;
            if(brr.find(data)!=brr.end()&&isfand.find(data)==isfand.end()) 
            {
                ans++;
                isfand.insert(data);
            }

        }
    }
    cout << ans << endl;
    return 0;
}