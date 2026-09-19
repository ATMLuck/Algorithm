#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int L;
    cin >> L;
    if(L==1)
    {
        cout << 0 << '\n';
        return 0;
    }
    else if(L==2)
    {
        cout << 2 << '\n' << 1 << '\n';
        return 0;
    }
    vector<int> prime(0);
    vector<bool> bar(L,true);
    for(int i = 2;i<L;i++)
    {
        if(bar[i]) prime.push_back(i);
        for(int vir : prime)
        {
            if((long long)i*vir>=L) break;
            bar[i*vir] = false;
            if(i%vir==0) break;
        }
    }
    int sum = 0,num = 0;
    for(int i = 0;i<(int)prime.size();i++) 
    {
        sum+=prime[i];
        if(sum<=L) 
        {
            cout << prime[i] << '\n';
            num++;
        }
        else break;
    }
    cout << num << endl;


    return 0;
}