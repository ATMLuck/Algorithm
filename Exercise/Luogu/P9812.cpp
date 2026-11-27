#include <iostream>
#include <vector>
using namespace std;
int lowbit(int vir) {return vir&(-vir);}
int sum_1(const vector<int> &t_arr, int n)
{
    int ans = 0;
    for(;n>0;n-=lowbit(n)) ans+=t_arr[n];
    return ans;
}
int sum_n(const vector<int> &t_arr, int a, int b) {return sum_1(t_arr,a<b?b:a)-sum_1(t_arr,a<b?a:b);}
void add_num(vector<int> &t_arr,int index,int num)
{
    for(;index<(int)t_arr.size();index+=lowbit(index)) t_arr[index]+=num;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> t_arr(n+1);
    for(int i = 0;i<=n;i++) t_arr[i] = lowbit(i);
    int ans = 0;
    while(m--)
    {
        int plane;
        cin >> plane;
        // if(plane==1)
        // {
        //     if(t_arr[1]) {add_num(t_arr,1,-1);ans++;continue;}
        //     else {cout << ans << endl;return 0;}
        // }
        int L = 1,R = plane;
        while(1)
        {
            int mid = (L+R)/2;
            if(L==1&&R==1)
            {
                if(t_arr[1]) {add_num(t_arr,1,-1);ans++;break;}
                else
                {
                    cout << ans << endl;
                    return 0;
                }
            }
            if(sum_n(t_arr,mid,R))
            {
                if(mid == R-1) {ans++;add_num(t_arr,R,-1);break;}
                else L=mid;
            }
            else
            {
                R = mid;
            }
        }
        
    }
    cout<< ans << endl;
    return 0;
}