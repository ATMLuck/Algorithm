#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Peo
{
public:
    string name;
    int year;
    int month;
    int day;
    int id;
};
bool cmp(Peo a, Peo b)
{
    if(a.year!=b.year) return a.year < b.year;
    else if(a.month!=b.month) return a.month < b.month;
    else if(a.day!=b.day) return a.day<b.day;
    else return a.id>b.id;
}
int main()
{
    int n;
    cin >> n;
    vector<Peo> arr(n);
    for(int i = 0;i<n;i++) 
    {
        cin >> arr[i].name >> arr[i].year >> arr[i].month >> arr[i].day;
        arr[i].id = i;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(const auto &vir : arr) cout << vir.name << '\n';

    return 0;
}