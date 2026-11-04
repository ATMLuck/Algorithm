#include "iostream"
#include "vector"
using LL=unsigned long long;
using namespace std;
vector<LL> prim()
{
    vector<LL> prime;
    vector<bool> tmp(100000001,true);

    for(LL i = 2;i<=100000000;i++)
    {
        if(tmp[i]) prime.push_back(i);
        for(auto vir:prime)
        {
            if(vir*i>100000000L) break;
            tmp[vir*i] = false;
            if(i%vir==0) break;
        }
    }
    return prime;
}
vector<LL> huiwen(vector<LL> &arr)
{
    vector<LL> ans;
    
    for(auto vir:arr)
    {
        vector<int> stack1;
        while(vir!=0)
        {
            int tmp = vir%10;
            stack1.push_back(tmp);
            vir/=10;
        }
        vector<int>::iterator a = stack1.begin(),b = stack1.end()-1;
        bool _is = true;
        while(a<=b)
        {
            if(*a!=*b) 
            {
                _is = false;
                break;
            }
            a++;b--;
        }
        if(_is) ans.push_back(vir);
    }
    return ans;
}

int main()
{
    vector<LL> tmp = prim();
    vector<LL> arr = huiwen(tmp);
    for(int i = 0;i<20;i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}