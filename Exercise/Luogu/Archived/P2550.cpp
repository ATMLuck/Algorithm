#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void input(unordered_set<int> &vir)
{
    for(int i = 0;i < 7;i++)
    {
        int data;
        cin >> data;
        vir.insert(data);
    }
}
void input(vector<int> &vir)
{
    for(int i = 0;i < 7;i++)
    {
        int data;
        cin >> data;
        vir.push_back(data);
    }
}
int main()
{
    int n;
    cin >> n;
    unordered_set<int> value;
    input(value);
    vector<int> ans(7,0);
    for(int i = 0;i<n;i++)
    {
        vector<int> k(0);
        input(k);
        int p = 7;
        for(int vir:k)
        {
            if(value.find(vir)!=value.end()) p--;
        }
        ans[p]++;
    }
    for(int a:ans) cout << a << ' ';
    cout << endl;
    return 0;
}