#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct station 
{
    double dis;
    double price;
};
struct Oil
{
    double cap;
    double price;
    Oil(double a,double b):cap(a),price(b){}
    double GetValue(double a = -1){return (a<cap&&a>0?a:cap)*price;}
};
struct car
{
    vector<Oil> oil = {};
    double C = 0;
    double C_now = 0;
    double ans = 0;
    void check(){sort(oil.begin(),oil.end(),[](Oil a,Oil b)->bool{return a.price<b.price;});}
    void revert(Oil vir)
    {
        ans-=vir.GetValue();
        C_now-=vir.cap;
    }
    void add(station vir)
    {
        for(int i = 0;i<oil.size();i++)
        {
            if(vir.price<oil[i].price)
            {
                for(int j = i;j<oil.size();j++)
                {
                    revert(oil[j]);
                }
                oil.resize(i);
                oil.push_back(Oil(C-C_now,vir.price));
                C_now = C;
                return;
            }
        }
        oil.push_back(Oil(C-C_now,vir.price));
        C_now = C;
        ans+=vir.price*(C-C_now);
    }
    void Go(double dis,double L)
    {
        while(dis>(oil.begin()->cap)*L)
        {
            dis-=(oil.begin()->cap)*L;
            oil.erase(oil.begin());
        }
        
    }
};

int main()
{
    double  S,C,L,P0;
    int N;
    cin >> S >> C >> L >> P0 >>N;
    vector<station> arr(N);
    for(int i;i<N;i++)
    {
        cin >> arr[i].dis >> arr[i].price;
    }

    return 0;
}