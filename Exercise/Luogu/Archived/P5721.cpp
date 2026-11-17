#include <iostream>
#include <utility>
using namespace std;
struct Int
{
    pair<int,int> data;
    Int(int a,int b)
    {
        data.first = a;
        data.second = b;
    }
    void check()
    {
        if(data.second<10) return;
        data.first += data.second/10;
        data.second%=10;
    }
    void add()
    {
        data.second++;
        check();
    }
    void print()
    {
        putchar(data.first+'0');
        putchar(data.second+'0');
    }
};
int main()
{
    int n;
    cin >> n;
    Int tmp(0,0);
    for(int i = 0;i<n;i++)
    {
        for(int j = n;j>i;j--)
        {
            tmp.add();
            tmp.print();
        }
        putchar('\n');
    }
    return 0;
}