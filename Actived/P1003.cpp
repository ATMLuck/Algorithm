#include <iostream>
#include <vector>
using namespace std;
class DT
{
public:
    int x;
    int y;
    int Lx;
    int Ly;
    bool isPointInDT(int Point_x,int Point_y)
    {
        if(x<=Point_x&&Point_x<=x+Lx&&y<=Point_y&&Point_y<=y+Ly)
            return true;
        return false;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<DT> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i].x >> arr[i].y
        >> arr[i].Lx >> arr[i].Ly;
    }
    int x,y;
    cin >> x >> y;
    int ans = -1;
    for(int i = 0;i<n;i++)
    {
        if(arr[i].isPointInDT(x, y)&&i+1>ans) ans = i+1;
    } 
    cout << ans << endl;
    return 0;
}