#include <queue>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    queue<int> arr;
    //for(int i = 0;i<n;i++) {int data;cin >> data;arr.push(data);}
    int size = 0;
    int str = ' ';
    int sum = 0;
    while(sum<n*n)
    {
        cin >> str;
        arr.push(str);
        size++;
        sum+=str;
    }
    int vir = 0;
    for(int i = 0;i<size;i++) 
    {
        for(int j = 0;j<arr.front();j++) arr.push(vir);
        vir^=1;
        arr.pop();
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++) {cout << arr.front();arr.pop();}
        cout << endl;
    }
    return 0;
}