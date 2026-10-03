#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
class Point
{
public:
    int x;
    int y;
    int z;
};
double line(Point a,Point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));}
int main()
{
    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    sort(arr.begin(),arr.end(),[](Point a,Point b)->bool{return a.z<b.z;});
    double ans = 0.0;
    for(int i = 1;i<n;i++) ans+=line(arr[i],arr[i-1]);
    printf("%.3lf",ans);
    return 0;
}