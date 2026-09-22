#include <cstdio>
#include <unordered_map>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int vir = -1;
    unordered_map<int,int> ans;
    for(int i = 1;i<=n;i++)
    {
        int data;
        scanf("%d",&data);
        if(vir<data) ans.insert({data,i});
        vir = data;
    }
    while(m--)
    {
        int data;
        scanf("%d",&data);
        if(ans.find(data)!=ans.end()) printf("%d ",ans[data]);
        else printf("-1 ");
    }
    return 0;
}