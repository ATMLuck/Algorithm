#include <iostream>
using namespace std;
class Int
{
public:
    int sum = 0;
    int num = 0;
    double pin()
    {
        return (double)sum/num;
    }
};
int main()
{
    int n,k;
    cin >> n >> k;
    Int a,b;
    for(int i = 1;i<=n;i++)
    {
        if(i%k==0)
        {
            a.sum+=i;
            a.num++;
        }
        else 
        {
            b.sum+=i;
            b.num++;
        }
    }
    printf("%.1lf %.1lf",a.pin(),b.pin());

}