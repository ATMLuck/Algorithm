#include <iostream>
#include <string>
#include <vector>
using namespace std;
char k[] = {'0','1','2','3','4','5','6','7','8','9','X'};
int main()
{
    string str;
    cin >> str;
    vector<int> arr(0);
    for(auto s:str)
        if(s!='-')
            arr.push_back(s-'0');
    int last = 0;
    for(int i = 1;i<10;i++)
    {
        last+=arr[i-1]*i;
        last%=11;
    }

    if(k[last]==arr[9]+'0')
    {
        cout << "Right" << endl;
        return 0;
    }
    *(str.end()-1) = k[last];
    cout<< str << endl;
    return 0;
}