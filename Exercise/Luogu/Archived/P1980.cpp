#include <iostream>
#include <vector>
#include <string>
using namespace std;
void cut(vector<int> &arr,int &size)
{
    arr[0]--;
    for(int i = 0;i<size;i++)
    {
        if(arr[i]<0&&i!=size-1)
        {
            arr[i+1]--;
            arr[i]+=10;
        }
        else
            break;
    }
    while(size!=0&&arr[size-1]==0) size--;
}
int find(const vector<int> &arr,int x,int size)
{
    int ans = 0;
    for(int i = 0;i<size;i++)
    {
        if(arr[i]==x) ans++;
    }
    return ans;
}
int main()
{
    int x,num_n;
    string n;
    cin >> n >> x;
    int size = n.size();
    num_n = std::stoi(n);
    vector<int> arr(size);
    for(int i = 0;i<size;i++)
    {
        arr[i] = n[size-i-1]-'0';
    }
    int ans = 0;
    while(num_n--)
    {
        ans+=find(arr,x,size);
        cut(arr,size);
    }
    cout << ans << endl;
    return 0;
}