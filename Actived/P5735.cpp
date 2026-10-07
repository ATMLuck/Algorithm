#include <cmath>
#include <iostream>
using namespace std;
double dis(double x1,double y1,double x2,double y2) {return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));}
int main()
{
    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;
    double ans = 0.0;
    ans += dis(x1,y1,x2,y2);
    ans += dis(x1,y1,x3,y3);
    ans += dis(x3,y3,x2,y2);
    printf("%.2lf",ans);
    return 0;
}