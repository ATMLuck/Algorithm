#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
class boot
{
public:
    int time;
    vector<int> count;
};
int main()
{
    int n;
    cin >> n;
    queue<boot> list;
    unordered_map<int,int> ans_size;
    for(int i = 0;i<n;i++)
    {
        int t,k;
        cin >> t >> k;
        boot temp;
        temp.time = t;
        while(k--)
        {
            int data;
            cin >> data;
            temp.count.push_back(data);
        }
        list.push(temp);
        vector<int>::iterator id = temp.count.begin();
        for(int j = 0;j<temp.count.size();j++)
        {
            if(ans_size.find(*id)==ans_size.end()) ans_size.insert({*id,0});
            ans_size[*id]++;
            id++;
        }
        while(list.front().time<=t-86400)
        {
            id = list.front().count.begin();
            for(int j = 0;j<list.front().count.size();j++)
            {
                if(ans_size[*id]>0) ans_size[*id]--;
                if(ans_size[*id]==0) ans_size.erase(*id);
                id++;
            }    
            list.pop();
        }
        cout << ans_size.size() << endl;

    }
    return 0;
}