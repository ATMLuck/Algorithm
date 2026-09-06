#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    string::iterator p = arr.begin();
    stack<char> tone;
    string ans;
    while(p<arr.end())
    {
        if(tone.empty()) 
        {
            tone.push(*p);
            p++;
            continue;
        }
        else
        {
            if(*p=='('||*p=='[') tone.push(*p);
            else if(*p==')'&&tone.top()!='('||*p==']'&&tone.top()!='[') tone.push(*p);
            else
            {
                ans+=*p;
                ans = tone.top()+ans;
                tone.pop();
            }
            p++;
        }
    }
    while(!tone.empty())
    {
        switch (tone.top())
        {
        case '(':
        case ')':
            ans = "()" + ans;
            break;
        case '[':
        case ']':
            ans = "[]" + ans;
            break;
        }
        tone.pop();
    }
    cout << ans << endl;
    return 0;
}