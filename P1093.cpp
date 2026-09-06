#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
class stu
{
public:
    int id;
    int sum;
    int chinese;
};
bool cph(const stu &a,const stu &b)
{
    if(a.sum!=b.sum) return a.sum > b.sum;
    else if(a.chinese!=b.chinese) return a.chinese > b.chinese;
    else return a.id < b.id;
}
int main()
{
    int n;
    cin >> n;
    vector<stu> arr(n);
    for(int i = 0;i<n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        arr[i].sum = a+b+c;
        arr[i].chinese = a;
        arr[i].id = i+1;
    }
    sort(arr.begin(),arr.end(),cph);
    for(int i = 0;i<5;i++) cout << arr[i].id << ' ' << arr[i].sum << '\n';

    return 0;
}