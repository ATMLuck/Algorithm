#include <iostream>
#define endl '\n'
using namespace std;
int main()
{
    int p[85];
    for(int i = 0;i<85;i++) p[i] = 0;
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    for(int i = 1;i<=s1;i++)
    {
        for(int j = 1;j<=s2;j++)
        {
            for(int k = 1;k<=s3;k++)
            {
                p[i+j+k]++;
            }
        }
    }
    int ans = 0,num = 0;
    for(int i = 0;i<85;i++)
    {
        if(p[i]>num)
        {
            num = p[i];
            ans = i;
        }
    }
    cout << ans << endl;
    
    return 0;
}