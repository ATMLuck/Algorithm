#include "iostream"
#include "vector"

using namespace std;
int main()
{
    long long B_x,B_y,H_x,H_y;
    cin >> B_x >> B_y >> H_x >> H_y;

    vector<vector<long long>> arr(B_x+1,vector<long long> (B_y+1,0)),
    brr(B_x+1,vector<long long> (B_y+1,0));
    brr[H_x][H_y] = 1;
    if(H_x>=2&&H_y>=1)brr[H_x-2][H_y-1] = 1;
    if(H_x>=2&&H_y<=B_y-1)brr[H_x-2][H_y+1] = 1;
    if(H_x>=1&&H_y>=2)brr[H_x-1][H_y-2] = 1;
    if(H_x>=1&&H_y<=B_y-2)brr[H_x-1][H_y+2] = 1;
    if(H_x<=B_x-1&&H_y>=2)brr[H_x+1][H_y-2] = 1;
    if(H_x<=B_x-1&&H_y<=B_y-2)brr[H_x+1][H_y+2] = 1;
    if(H_x<=B_x-2&&H_y>=1)brr[H_x+2][H_y-1] = 1;
    if(H_x<=B_x-2&&H_y<=B_y-1)brr[H_x+2][H_y+1] = 1;
    bool is_ = true;
    for(int i = 0;i<arr.size();i++)
    {
        if(brr[i][0]) is_ = false;
        if(is_)
        {
            arr[i][0] = 1;
        }
    }
    is_ = true;
    for(int i = 0;i<arr[1].size();i++)
    {
        if(brr[0][i]) is_ = false;
        if(is_)
        {
            arr[0][i] = 1;
        }
    }
    for(int i = 1;i<arr.size();i++)
    {
        for(int j = 1;j<arr[1].size();j++)
        {
            if(brr[i][j]) continue;
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    cout << arr[B_x][B_y] << endl;
    return 0;
}