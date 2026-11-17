#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string line;
    cin >> line;
    int n = line.size();
    vector<int> ans;
    char mode = '0';
    int tmp = 0;
    for(int i = 1;i<=n;i++)
    {
        if(i!=1) cin >> line;
        for(char vir:line)
        {
            if(vir==mode) tmp++;
            else
            {
                ans.push_back(tmp);
                tmp = 1;
                mode = vir;
            }
        }
    }
    ans.push_back(tmp);
    cout << n << ' ';
    for(int i:ans) cout << i << ' ';
    cout << endl;

    return 0;
}