#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<bool> prime()
{
    vector<int> pri(0);
    vector<bool> arr(1000,true);
    for(int i = 2;i<100;i++)
    {
        if(arr[i]) pri.push_back(i);
        for(const int &vir : pri)
        {
            if(vir*i>=100) break;
            arr[vir*i] = false;
            if(i%vir==0) break;
        }
    }
    arr[0] = false;
    arr[1] = false;
    return arr;
}
int main()
{
    int letter[26] = {0};
    string str;
    cin >> str;
    for(const char &vir : str)
    {
        letter[(unsigned int)(vir-'a')]++;
    }
    sort(letter,letter+26);
    int maxn = letter[25];
    int minn;
    for(int a : letter) if(a!=0) {minn = a;break;}
    vector<bool> arr = prime();
    if(arr[maxn-minn])
    {
        cout << "Lucky Word" << endl << maxn-minn << endl;
    }
    else
    {
        cout << "No Answer\n0" << endl;
    }

    return 0;
}