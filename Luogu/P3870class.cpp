#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
class Node
{
public:
    int Left;
    int Right;
    int Lazy;
    int Data;
};
void build(vector<Node>& Tree,int vir,int L,int R)
{
    if(L==R)
    {
        Tree[vir] = {L,R,0,0};
        return;
    }
    int mid = (L+R)/2;
    build(Tree,vir<<1,L,mid);
    build(Tree,vir<<1|1,mid+1,R);
    Tree[vir] = {L,R,0,Tree[vir<<1].Data+Tree[vir<<1|1].Data};
}
void PushDown(vector<Node>& Tree,int vir)
{
    if (Tree[vir].Left == Tree[vir].Right || Tree[vir].Lazy == 0)
        return;
    int lc = vir << 1;
    int rc = vir << 1 | 1;

    Tree[lc].Data = (Tree[lc].Right - Tree[lc].Left + 1) - Tree[lc].Data;
    Tree[lc].Lazy ^= 1;
    Tree[rc].Data = (Tree[rc].Right - Tree[rc].Left + 1) - Tree[rc].Data;
    Tree[rc].Lazy ^= 1;
    Tree[vir].Lazy = 0;
}
void Update(vector<Node>& Tree,int vir,int L,int R)
{
    int mid = (Tree[vir].Left+Tree[vir].Right)/2;
    if(L==Tree[vir].Left&&R==Tree[vir].Right)
    {
        Tree[vir].Data = (Tree[vir].Right-Tree[vir].Left+1)-Tree[vir].Data;
        Tree[vir].Lazy^=1;
        return;
    }
    PushDown(Tree,vir);
    if(L<=mid)
    {
        Update(Tree,vir<<1,L,min(R,mid));
        if(R>mid) Update(Tree,vir<<1|1,mid+1,R);
    }
    else Update(Tree,vir<<1|1,L,R);
    Tree[vir].Data = Tree[vir<<1].Data+Tree[vir<<1|1].Data;
}
int Find(vector<Node>& Tree,int vir,int L,int R)
{
    int mid = (Tree[vir].Left+Tree[vir].Right)/2;
    if(L==Tree[vir].Left&&R==Tree[vir].Right)
    {
        return Tree[vir].Data;
    }
    PushDown(Tree,vir);
    int ans = 0;
    if(L<=mid)
    {
        ans += Find(Tree,vir<<1,L,min(R,mid));
        if(R>mid) ans+=Find(Tree,vir<<1|1,mid+1,R);
        return ans;
    }
    else return Find(Tree,vir<<1|1,L,R);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<Node> Tree(4*n+10);
    build(Tree,1,1,n);
    while(m--)
    {
        int c,a,b;
        scanf("%d %d %d",&c,&a,&b);
        if(c) printf("%d\n",Find(Tree,1,a,b));
        else Update(Tree,1,a,b);
    }
    return 0;
}