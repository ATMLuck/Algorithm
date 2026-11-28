#include <vector>
#include <iostream>
#include <utility>

using namespace std;
void ad(vector<char> &str ,int index)
{
    if(index>=999||index<0) return;
    str[index]+=1;
    str[index+1]-=31;
}
void Out(const vector<char> &str)
{
    for(char v:str) putchar(v);
    putchar('\n');
}
int main()
{
    vector<char> str(1000,'a');

    int k;
    cin >> k;
    while(k--)
    {
        Out(str);
        ad(str,k-1);
    }
    return 0;
}