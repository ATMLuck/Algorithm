#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr(3);
    string str;
    for(int i = 0;i<3;i++) cin >> arr[i];
    cin >> str;
    sort(arr.begin(),arr.end(),[](int a,int b)->bool{return a>b;});
    int a = arr[2],b = arr[1],c=arr[0];
    for(auto vir:str)
    {
        if(vir=='A') {cout << a << ' ';continue;}
        else if(vir=='B') {cout << b << ' ';continue;}
        else if(vir=='C') {cout << c << ' ';continue;}
    }
    return 0;
}