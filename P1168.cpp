#include "bits/stdc++.h"
#include "iostream"
typedef long long LL;
using namespace std;
int main()
{
    LL n,mid;
    cin >> n;
    priority_queue<LL> M_arr;
    priority_queue<LL,vector<LL>,greater<LL>> B_arr;
    for(int i = 0;i<n;i++)
    {
        cin >> mid;
        if(i==0)
        {
            cout<< mid <<endl;
            M_arr.push(mid);
            continue;
        }
        if(i==1)
        {
            if(mid>M_arr.top()) B_arr.push(mid);
            else 
            {
                B_arr.push(M_arr.top());
                M_arr.pop();
                M_arr.push(mid);
            }
            continue;
        }
        if(M_arr.size()==B_arr.size())
        {
            if(mid<M_arr.top())
            {
                M_arr.push(mid);
                mid = M_arr.top();
                M_arr.pop();
            }
            else if(mid>B_arr.top())
            {
                B_arr.push(mid);
                mid = B_arr.top();
                B_arr.pop();
            }
            cout << mid << endl;
            M_arr.push(mid);
        }
        else
        {
            if(mid<M_arr.top())
            {
                M_arr.push(mid);
                B_arr.push(M_arr.top());
                M_arr.pop();
            }
            else B_arr.push(mid);
        }
    }
    return 0;
}