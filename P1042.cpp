#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
class pare
{
public:
    int first;
    int second;
    pare()
    {
        first = 0;
        second = 0;
    }
    void FirstAdd() {first++;}
    void SecondAdd() {second++;}
    void ToZero() {first = 0;second = 0;}
    void OutPut() {cout << first <<':' << second << '\n';}
};
int main()
{
    cin.tie(nullptr);
    char data;
    data = cin.get();
    pare sc11,sc21;
    vector<pare> ans_11,ans_21;
    while(data!='E')
    {
        if(data=='W') 
        {
            sc11.FirstAdd();
            sc21.FirstAdd();
        }
        else if(data=='L')
        {
            sc11.SecondAdd();
            sc21.SecondAdd();
        }
        if((sc11.first>=11||sc11.second>=11)&&(abs(sc11.first-sc11.second)>=2))
        {
            ans_11.push_back(sc11);
            sc11.ToZero();
        }
        if((sc21.first>=21||sc21.second>=21)&&(abs(sc21.first-sc21.second)>=2))
        {
            ans_21.push_back(sc21);
            sc21.ToZero();
        }
        data = cin.get();
    }
    ans_11.push_back(sc11);
    ans_21.push_back(sc21);
    for(pare vir:ans_11) vir.OutPut();
    cout << '\n';
    for(pare vir:ans_21) vir.OutPut();
    
    return 0;
}
