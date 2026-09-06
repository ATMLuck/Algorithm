#include "iostream"
#include "vector"
using namespace std;
class Node
{
public:
    int L = -1;
    int R = -1;
};
int main()
{
    int n;
    int front = 1;
    cin >> n;
    vector<Node> arr(n+1);
    for(int i = 2;i<=n;i++)
    {
        int k,p;
        cin >> k >> p;
        if(p==0)
        {
            if(arr[k].L==-1)
            {
                arr[k].L = i;
                arr[i].R = k;
                front = i;
            }
            else
            {
                int tempL = arr[k].L;
                arr[k].L = i;
                arr[tempL].R = i;
                arr[i].R = k;
                arr[i].L = tempL;
            }
        }
        else
        {
            if(arr[k].R==-1)
            {
                arr[k].R = i;
                arr[i].L = k;
            }
            else
            {
                int tempR = arr[k].R;
                arr[k].R = i;
                arr[tempR].L = i;
                arr[i].L = k;
                arr[i].R = tempR;
            }
        }
    }
    int m;
    cin >> m;
    while(m--)
    {
        int rmid;
        cin >> rmid;
        int idL = arr[rmid].L,idR = arr[rmid].R;
        if(idL==-1&&idR==-1) continue;
        else if(idL == -1)
        {
            arr[rmid].R = -1;
            arr[idR].L = -1;
            front = idR;
        }
        else if(idR == -1)
        {
            arr[rmid].L = -1;
            arr[idL].R = -1;
        }
        else
        {
            arr[rmid].L = -1;
            arr[rmid].R = -1;
            arr[idL].R = idR;
            arr[idR].L = idL;
        }
    }
    int vir = front;
    while (arr[vir].R!=-1) 
    {
        cout << vir <<' ';
        vir = arr[vir].R;
    }
    cout << vir << endl;
    return 0;
}