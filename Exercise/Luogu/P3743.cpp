#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int pay;
    int batry;
};

int main()
{
    int n,p;
    unsigned long long sum_pay=0;
    cin >> n >> p;
    vector<Node> arr(n);
    for(int i = 0;i < n; i++)
    {
        cin >> arr[i].pay >> arr[i].batry;
        sum_pay+=arr[i].pay;
    }
    if(sum_pay<=p){cout << -1 << '\n';return 0;}
    double lans=0.0,rans=1e10,s_pay = 0;
    int wh = 0;
    while(rans-lans>1e-6&&wh<100000000)
    {
        double mid_ans = (rans+lans)/2;
        for(int i = 0;i<n;i++)
        {
            double tmp_pay = arr[i].batry-arr[i].pay*mid_ans;
            if(tmp_pay<0) s_pay-=tmp_pay;
        }
        if(s_pay>p*mid_ans)
        {
            rans=mid_ans;
        }
        else
        {
            lans=mid_ans;
        }
        s_pay = 0;
        wh++;
    }
    cout << lans << endl;
    
    return 0;
}