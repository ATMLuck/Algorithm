#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
struct Peo
{
    int id;
    int score;
    int atk;
};
bool cmp(Peo a, Peo b)
{
    if(a.score==b.score) return a.id<b.id;
    return a.score>b.score;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,r,q;
    cin >> n >> r >> q;
    vector<Peo> arr(2*n);
    for(int i = 0;i<2*n;i++)
    {
        arr[i].id = i+1;
        cin >> arr[i].score;
    }
    for(int i = 0;i<2*n;i++)
    {
        cin >> arr[i].atk;
    }
    stable_sort(arr.begin(),arr.end(),cmp);
    while(r--)
    {
        for(int i = 1;i<2*n;i+=2)
        {
            if(arr[i-1].atk<arr[i].atk) arr[i].score++;
            else arr[i-1].score++;
        }
        stable_sort(arr.begin(),arr.end(),cmp);
    }
    cout << arr[q-1].id << endl;
    return 0;
}
