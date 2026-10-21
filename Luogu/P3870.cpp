#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
void build(vector<int>& tree,vector<int>& lazy,int L,int R,int vir)
{
    if(L==R)
    {
        tree[vir] = 0;
        return; 
    }
    int mid = (L+R)/2;
    build(tree,lazy,L,mid,vir<<1);
    build(tree,lazy,mid+1,R,vir<<1|1);
    tree[vir] = tree[vir<<1] + tree[vir<<1|1];
}
void PushDown(vector<int>& tree,vector<int>& lazy,int L,int R,int vir)
{
    if(L==R||lazy[vir]==0) return;
    int lc = vir<<1,rc = vir<<1|1,mid = (L+R)/2;
    tree[lc] = mid-L+1 - tree[lc];
    lazy[lc] ^= 1;
    tree[rc] = R-mid - tree[rc];
    lazy[rc] ^= 1;
    lazy[vir] = 0;
}
void Update(vector<int>& tree,vector<int>& lazy,int uL,int uR,int L,int R,int vir)
{
    PushDown(tree,lazy,L,R,vir);
    if(uL==L&&uR==R)
    {
        tree[vir] = R-L+1-tree[vir];
        lazy[vir] ^= 1;
    }
    else
    {
        int mid = (L+R)/2;
        if(uL<=mid) Update(tree,lazy,uL,min(uR,mid),L,mid,vir<<1);
        if(uR>=mid+1) Update(tree,lazy,max(uL,mid+1),uR,mid+1,R,vir<<1|1);
        tree[vir] = tree[vir<<1]+tree[vir<<1|1];
    }
    
}
int Find(vector<int>& tree,vector<int>& lazy,int fL,int fR,int L,int R,int vir)
{
    PushDown(tree,lazy,L,R,vir);
    if(fL==L&&fR==R)
    {
        return tree[vir];
    }
    else
    {
        int mid = (L+R)/2,ansL = 0,ansR = 0;
        if(fL<=mid) ansL = Find(tree,lazy,fL,min(fR,mid),L,mid,vir<<1);
        if(fR>=mid+1) ansR = Find(tree,lazy,max(fL,mid+1),fR,mid+1,R,vir<<1|1);
        return ansL+ansR;
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> tree(4*n,0);
    vector<int> lazy(4*n,0);
    build(tree,lazy,1,n,1);
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d",&c,&a,&b);
        if(c) printf("%d\n",Find(tree,lazy,a,b,1,n,1));
        else Update(tree,lazy,a,b,1,n,1);
    }
    return 0;
}