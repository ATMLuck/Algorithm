#include "bits/stdc++.h"
typedef long long LL;
using namespace std;
int main()
{
    LL n;
    cin >> n;
    vector<LL> arr(n);
    set<LL> att;
    for(LL i = 0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    if(arr[0]!=0) {cout << 0 << endl;return 0;}
    LL M = *(arr.end()-1);
    arr.pop_back();
    for(auto a:arr) att.insert(a);
    LL i = 0;
    while (att.find(i)!=att.end()) i++;
    cout << M*i << endl;
    return 0;
}