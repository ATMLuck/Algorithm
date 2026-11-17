#include <vector>
#include <string>
#include <iostream>
using namespace std;
string ToString(int data)
{
    string re = "";
    while(data)
    {
        re.push_back(data%10+'0');
        data/=10;
    }
    return re;
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<int> arr(10,0);
    for(;m<=n;m++)
    {
        string str = ToString(m);
        for(auto vir:str)
        {
            arr[vir-'0']++;
        }
    }
    for(int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}