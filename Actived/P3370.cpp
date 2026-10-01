#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ULL = unsigned long long;
const ULL base = 998244353ULL;
const ULL MOD = (ULL)(1ULL<<61)-1;

ULL Hash(string vir)
{
    int size = vir.size();
    ULL out = 0ULL;
    for(int i = 0;i<size;i++)
    {
        out *= base;
        out %= MOD;
        out += vir[i];
        out %= MOD;
    }
    return out;
}
int main()
{  
    int n;
    cin >> n;
    string data;
    vector<ULL> dictory;
    while(n--)
    {
        cin >> data;
        dictory.push_back(Hash(data));
    }
    sort(dictory.begin(),dictory.end());
    ULL vir = dictory[0];
    int ans = 1;
    for(ULL num:dictory)
    {
        if(num!=vir)
        {
            ans++;
            vir=num;
        }
    }
    cout << ans << endl;

    return 0;
}