#include <iostream>
#include <vector>
using namespace std;
const vector<vector<vector<char>>> NumberList=
{
    {
        {'X','X','X','.'},
        {'X','.','X','.'},
        {'X','.','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'}
    },
    {
        {'.','.','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'}
    },
    {
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'X','X','X','.'},
        {'X','.','.','.'},
        {'X','X','X','.'}
    },
    {
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'X','X','X','.'}
    },
    {
        {'X','.','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'}
    },
    {
        {'X','X','X','.'},
        {'X','.','.','.'},
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'X','X','X','.'}
    },
    {
        {'X','X','X','.'},
        {'X','.','.','.'},
        {'X','X','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'}
    },
    {
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'},
        {'.','.','X','.'}
    },
    {
        {'X','X','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'}
    },
    {
        {'X','X','X','.'},
        {'X','.','X','.'},
        {'X','X','X','.'},
        {'.','.','X','.'},
        {'X','X','X','.'}
    }
};
void add_vector(vector<vector<char>> &ans,int vir)
{
    for(int i = 0;i<5;i++)
    {
        for(char k:NumberList[vir][i]) ans[i].push_back(k);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(0);
    while(n!=(int)arr.size())
    {
        char data = cin.get();
        if(data>='0'&&data<='9') arr.push_back(data-'0');
    }
    vector<vector<char>> ans(5,vector<char> (0));
    for(int i:arr)
    {
        add_vector(ans,i);
    }
    for(int i = 0;i<5;i++) ans[i].erase(ans[i].end()-1);
    for(vector<char> i:ans)
    {
        for(char j:i) cout << j;
        cout << '\n';
    }
    return 0;
}