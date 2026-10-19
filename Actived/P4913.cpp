#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int L,R;
};
void DFS(const vector<Node> &tree,int vir,int deep,int &ans)
{
    ans = ans>deep?ans:deep;
    if(tree[vir].L!=0) DFS(tree,tree[vir].L,deep+1,ans);
    if(tree[vir].R!=0) DFS(tree,tree[vir].R,deep+1,ans);
}
int main()
{
    int n;
    cin >> n;
    vector<Node> tree(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin >> tree[i].L >> tree[i].R;
    }
    int ans = 0;
    DFS(tree,1,1,ans);
    cout << ans << endl;
    return 0;
}