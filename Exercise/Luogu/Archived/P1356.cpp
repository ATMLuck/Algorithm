#include <iostream>
#include <vector>
#include <utility>

using namespace std;
void solve();
int main()
{
    int m;
    cin >> m;
    while(m--) solve();
    return 0;
}
void MOD(int &vir, int k) {vir = (vir%k+k)%k;}
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<bool> mod_arr(k,false);
    MOD(arr[0], k);
    mod_arr[arr[0]] = true;
    for(int i = 1;i<n;i++)
    {
        vector<bool> new_mod_arr(k,false);
        for(int j = 0;j<k;j++)
        {
            if(!mod_arr[j])continue;
            int vir1 = j+arr[i],vir2 = j-arr[i];
            MOD(vir1,k);MOD(vir2,k);
            new_mod_arr[vir1] = true;
            new_mod_arr[vir2] = true;
        }
        mod_arr = std::move(new_mod_arr);
    }
    if(mod_arr[0]) cout << "Divisible" << '\n';
    else cout << "Not divisible" << '\n';
}