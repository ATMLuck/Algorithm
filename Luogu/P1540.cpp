#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    queue<int> arr;
    int size = 0,cnt = 0;
    unordered_set<int> brr;
    for(int i = 0;i<n;i++)
    {
        int data;
        cin >> data;
        if(brr.find(data)==brr.end())
        {
            if(!(size<m))
            {
                brr.erase(arr.front());
                arr.pop();
                size--;
            }
            arr.push(data);
            brr.insert(data);
            size++;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}