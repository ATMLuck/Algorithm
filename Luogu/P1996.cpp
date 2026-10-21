#include "iostream"
#include "queue"
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    queue<int> arr;
    for(int i = 1;i<=n;i++) arr.push(i);
    int id = 0;
    while(!arr.empty())
    {
        id++;
        if(id!=m)
        {
            arr.push(arr.front());
            arr.pop();
        }
        else
        {
            cout << arr.front() <<' ';
            arr.pop();
            id = 0;
        }
    }
    cout << endl;
    return 0;
}