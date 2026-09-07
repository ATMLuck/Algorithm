#include "iostream"
#include "string"
#include "vector"
#include "stack"
using namespace std;
class par
{
public:
    char t;
    int id;
};
int main()
{
    string s;
    cin >> s;
    vector<par> arr(s.size());
    for(int i = 0;i<s.size();i++)
    {
        arr[i].t = s[i];
        arr[i].id = i;
    }
    stack<par> temp;
    vector<bool> brr(s.size(),false);
    for(par& a:arr)
    {
        switch(a.t)
        {
        case '(':
        case '[':
            temp.push(a);
            break;
        case ')':
            if(!temp.empty()&&temp.top().t=='(')
            {
                brr[a.id] = true;
                brr[temp.top().id] = true;
                temp.pop();
            }
            break;
        case ']':
            if(!temp.empty()&&temp.top().t=='[')
            {
                brr[a.id] = true;
                brr[temp.top().id] = true;
                temp.pop();
            }
            break;
        }
    }
    string ans = "";
    for(int i = 0;i<brr.size();i++)
    {
        if(brr[i])
        {
            ans += s[i];
        }
        else
        {
            switch(s[i])
            {
            case '(':
            case ')':
                ans += "()";
                break;
            case '[':
            case ']':
                ans += "[]";
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}