#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
pair<int,int> findMin(const vector<int> &arr,int l,int r)
{
    pair<int,int> kr = {INT_MAX,INT_MAX};
    for(int i = l;i<r;i++) 
    {
        if(kr.first>arr[i])
        {
            kr.first = arr[i];
            kr.second = i;
        }
    }
    return kr;
}
int main()
{
    string num;
    int k;
    cin >> num >> k;
    vector<int> arr(num.size()),ANS(0);
    for(int i = 0;i<(int)num.size();i++) {arr[i] = num[i]-'0';}
    k = (int)num.size()-k;
    pair<int,int> ans = {0,0};
    while(k--)
    {
        ans = findMin(arr,ans.second,(int)num.size()-k);
        ans.second++;
        ANS.push_back(ans.first);
    }
    if(ANS.size()==1&&ANS[0]==0) 
    {
        cout << 0 << endl;
        return 0;
    }
    bool tmp = true;
    for(int vir:ANS)
    {
        if(tmp&&vir==0)continue;
        tmp = false;
        cout << vir;
    }
    cout << endl;
    return 0;
}