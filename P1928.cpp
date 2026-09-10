#include "iostream"
#include "string"
#include "stack"

using namespace std;
namespace IO
{
    string output(string &vir ,int head,int tile)
    {
        string ans = "";
        while(head<=tile&&(vir[head]<'0'||vir[head]>'9'))
        {
            if(vir[head]!='['&&vir[head]!=']')
            {
                ans += vir[head];
            }
            head++;
        }
        if(head>tile) return ans;
        string value_str = "";
        while (vir[head]>='0'&&vir[head]<='9') {value_str+=vir[head];head++;}
        int vlaue = stoi(value_str);
        int l = 0,mid = head;
        while(1)
        {
            if(vir[mid]=='[') l++;
            else if(vir[mid]==']')
            {
                if(l==0) break;
                else l--;
            }
            mid++;
        }
        while(vlaue--) ans+=IO::output(vir,head,mid-1);
        ans += IO::output(vir,mid,tile);
        return ans;
    }
}
int main()
{
    string vir;
    cin >> vir;
    cout << IO::output(vir,0,vir.size()-1);
    return 0;
}