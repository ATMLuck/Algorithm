#include <cstdio>
#include <iostream>
using namespace std;
double a,b,c,d;
double f(double x) {return a*x*x*x+b*x*x+c*x+d;}
//double f(double x) {return a*x*x*x+b*x*x+c*x+d;}
double half_find(double l,double r)
{
    double mid = (l+r)/2;
    if(r-l<0.01) return mid;
    
    if(f(l)*f(mid)>0) return half_find(mid, r);
    else return half_find(l,mid);

}
int main()
{
    
    cin >> a >> b >> c >> d;
    for(int i = -100;i<100;i++)
    {
        if(f(i)==0) printf("%d.00 ",i);
        if(f((double)i)*f((double)(i+1))>=0)
            continue;
        else
            printf("%.2lf ",half_find((double)i,(double)(i+1)));
    }
    printf("\n");
    return 0;
}
