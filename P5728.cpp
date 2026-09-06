#include "iostream"
#include "vector"
using namespace std;
class Node
{
public:
    int sum;
    int a;
    int b;
    int c;
    void add()
    {
        sum = a+b+c;
    }
};
bool com(Node a,Node b)
{
    if(a.sum - b.sum>=-10&&a.sum - b.sum<=10)
    {
        if(a.a - b.a>=-5&&a.a - b.a<=5&&a.b - b.b>=-5&&a.b - b.b<=5&&a.c - b.c>=-5&&a.c - b.c<=5)
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int nr = n;
    vector<Node> arr;
    while(nr--)
    {
        Node temp;
        cin >> temp.a >> temp.b >> temp.c;
        temp.add();
        arr.push_back(temp);
    }
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(com(arr[i],arr[j])) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}