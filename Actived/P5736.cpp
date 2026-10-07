#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;
unordered_set<int> prime()
{
    unordered_set<int> ans;
    vector<int> arr(0);
    vector<bool> brr(100005,true);
    for(int i = 2;i<=100001;i++)
    {
        if(brr[i]){arr.push_back(i);ans.insert(i);}
        for(int j:arr)
        {
            if(i*j>=100001) break;
            brr[i*j] = false;
            if(i%j==0) break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    unordered_set<int> pri = prime();
    for(int i:arr) if(pri.find(i)!=pri.end()) cout << i << ' ';
    cout << endl;
    return 0;
}