#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

struct Node
{
    string name;
    int a,b,c,sum;
};
bool cmp(Node _a,Node _b)
{
    if(abs(_a.a-_b.a)<=5&&abs(_a.b-_b.b)<=5&&abs(_a.c-_b.c)<=5&&abs(_a.a-_b.a)<=5&&abs(_a.sum-_b.sum)<=10)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    vector<Node> arr(n);
    for(int i = 0;i<n;i++) {cin >>arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;arr[i].sum = arr[i].a+arr[i].b+arr[i].c;}
    sort(arr.begin(),arr.end(),[](Node _a,Node _b)->bool {return _a.name<_b.name;});
    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(cmp(arr[i],arr[j]))
            {
                cout << arr[i].name << ' ' << arr[j].name << endl;
            }
        }
    }
    return 0;
}