#include "iostream"
using namespace std;
int main()
{
    int a[7] = {0};
    int vir = -1,nano = -1;
    for(int i = 0;i<7;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a+b>8)
        {
            if(a+b>nano) 
            {
                nano = a+b;
                vir = i+1;
            }
        }
    }
    if(vir!=-1){
        cout << vir << endl;
    }else{
        cout << 0 << endl;
    } 
    return 0;
}