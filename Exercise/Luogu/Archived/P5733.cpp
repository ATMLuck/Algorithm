#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    for(char &vir:str) if(vir>='a'&&vir<='z') vir -= 32;
    cout << str << endl;
    return 0;
}
