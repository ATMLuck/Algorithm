#include <iostream>
#include <map>
#include <climits>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int scan(map<int,int> &arr)
{
    int ans = 0;
    vector<map<int,int>::iterator> isDistroy;

    map<int,int>::iterator it=arr.begin(),itx = it;itx++;
    isDistroy.push_back(it);
    ans++;
    while(itx!=arr.end())
    {
        if(itx->first==it->first+1&&itx->second>=it->second)
        {
            isDistroy.push_back(itx);
            ans++;
        }else break;
        it++;
        itx++;
    }
    for(auto p:isDistroy)
    {
        p->second--;
        if(p->second==0) arr.erase(p);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int,int> arr; 
    for(int i=0;i<n;i++)
    {
        int data;
        cin >> data;
        arr[data]++;
    }
    int ans = INT_MAX;
    while(arr.size()>0) ans = min(ans,scan(arr));
    cout << ans << endl;
    return 0;
}
