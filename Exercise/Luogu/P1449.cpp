#include "iostream"
#include "stack"
#include "string"

using namespace std;
int main()
{
    string str = "";
    char temp;
    stack<int> arr;
    temp = cin.get();
    while(temp != '@')
    {
        if(temp>='0'&&temp<='9') str+=temp;
        else if(temp=='.') 
        {
            int num = stoi(str);
            str = "";
            arr.push(num);
        }
        else
        {
            int a,b;
            switch(temp)
            {
            case '+':
                b = arr.top();
                arr.pop();
                a = arr.top();
                arr.pop();
                arr.push(a+b);
                break;
            case '-':
                b = arr.top();
                arr.pop();
                a = arr.top();
                arr.pop();
                arr.push(a-b);
                break;
            case '*':
                b = arr.top();
                arr.pop();
                a = arr.top();
                arr.pop();
                arr.push(a*b);
                break;
            case '/':
                b = arr.top();
                arr.pop();
                a = arr.top();
                arr.pop();
                arr.push(a/b);
                break;
            }
        
        }
    temp = cin.get();
    }
    cout << arr.top() << endl;
    return 0;
}