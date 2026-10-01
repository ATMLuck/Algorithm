#include <iostream>
#include <vector>
using namespace std;
int cost_time(int np)
{
    vector<int> arr(np);
    int sum = 0;
    for(int i = 0;i<np;i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    int half = sum/2;
    vector<int> DP(1<<np,0);
    for(int S = 0;S<DP.size();S++)
    {
        for(int i = 0;i<np;i++)
        {
            if((S>>i)&1) DP[S] += arr[i];
        }
    }
    int base = -1;
    for(int vir:DP)
        if(vir<=half&&vir>base)
            base = vir;
    return sum-base;
}
int main()
{
    int List[4];
    for(int i = 0;i<4;i++) cin >> List[i];
    long long ans = 0;
    for(int vir : List) ans+=cost_time(vir);
    cout << ans << endl;
    
    return 0;
}
/*
1 2 1 3		
5
4 3
6
2 4 3

20
*/