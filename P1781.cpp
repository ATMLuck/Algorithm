#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class peo
{
public:
    int id;
    string score;
};
bool kcp(peo a,peo b)
{
    if(a.score.size()!=b.score.size()) return a.score.size()>b.score.size();
    for(int i = 0;i<a.score.size();i++)
    {
        if(a.score[i]!=b.score[i])
            return a.score[i]>b.score[i];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<peo> arr(n);
    for(int i = 0;i<n;i++)
    {
        arr[i].id = i+1;
        cin >> arr[i].score;
    }
    sort(arr.begin(),arr.end(),kcp);
    cout << arr[0].id <<'\n' << arr[0].score << '\n';
    return 0;
}