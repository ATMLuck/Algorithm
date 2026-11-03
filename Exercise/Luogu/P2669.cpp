#include <iostream>
using namespace std;
int main()
{
    int k,x = 1;
    unsigned long long ANS = 0;
    cin >> k;
    while(k)
    {
        for(int i = 0;i<x;i++)
        {
            ANS+=x;
            k--;
            if(!k) break;
        }
        x++;
    }
    cout << ANS << endl;
    return 0;
}