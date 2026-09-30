#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n >> str;
    for(char &vir : str)
    {
        int a = (int)vir;
        a+=n;
        if(a>(int)'z') a-=26;
        vir = (char)a;
    }
    cout << str << endl;
    return 0;
}