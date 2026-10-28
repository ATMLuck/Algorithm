#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ULL = unsigned long long;

class Node
{
public:
    int id;
    int score;
};
bool cmp(Node a, Node b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return a.id < b.id;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<Node> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i].id >> arr[i].score;
    sort(arr.begin(),arr.end(),cmp);
    int score_line = arr[(ULL)(1.5*m-1)].score;
    vector<Node> brr(0);
    ULL num = 0;
    for(const auto &vir : arr)
    {
        if(vir.score>=score_line)
        {
            brr.push_back(vir);
            num++;
        }
    }
    cout << score_line << ' ' << num << '\n';
    for( const auto &vir : brr) cout << vir.id << ' ' << vir.score << '\n';
    return 0;
}