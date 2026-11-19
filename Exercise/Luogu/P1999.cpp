#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<int> revert(vector<int> &arr)
{
    int size = arr.size();
    vector<int> re(0);
    for(int i = size-1;i>=0;i--)
    {
        re.push_back(arr[i]);
    }
    return re;
}
void add(vector<int> &a, vector<int> &b)
{
    int size = a.size();
    for(int i = 0;i<size;i++) a[i] +=b[i];
    for(int i = 0;i<size;i++)
    {
        int next = a[i]/N;
        a[i]%=N;
        if(next==0) continue;;
        if(i!=size-1) a[i+1]+=next;
        else a.push_back(next);
    }
}
bool check(vector<int> &arr)
{
    int size = arr.size();
    bool re = true;
    for(int L=0,R=size-1;L<R;L++,R--)
    {
        if(arr[L]!=arr[R])
        {
            re = false;
            break;
        }
    }
    return re;
}
void input(vector<int> &arr)
{
    string tmp;
    cin >>tmp;
    arr.clear();
    for(int i = tmp.size()-1;i>=0;i--)
    {
        if(tmp[i]>='0'&&tmp[i]<='9') arr.push_back(tmp[i]-'0');
        else arr.push_back(tmp[i]-'A'+10);
    }
}
int main()
{
    cin >> N;
    vector<int> arr;
    input(arr);
    int step = 0;
    bool isR = false;
    for(int i=0;i<30;i++)
    {
        if(check(arr)) {isR=true;break;}
        vector<int> t = revert(arr);
        add(arr, t);
        step++;
    }
    if(isR)
    {
       cout << "STEP=" << step << endl; 
    }
    else {
        cout << "Impossible!" << endl;
    }

    return 0;
}