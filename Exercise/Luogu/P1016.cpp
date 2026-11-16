#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
using db=double;
class Station
{
public:
    db dis;
    db value;
    Station() = default;
    Station(db a, db b):dis(a),value(b){}
};
class Oil
{
public:
    db cap;
    db value;
    Oil() = default;
    Oil(db a, db b):cap(a),value(b){}
};
class Car
{
public:
    vector<Oil> OilBox;
    db Box_sum;
    db Box_now;
    db cost;
    Car(db C):OilBox({}),Box_sum(C),Box_now(0),cost(0){}
    void check()
    {
        sort(OilBox.begin(),OilBox.end(),[](Oil a, Oil b)->bool{return a.value<b.value;});
    }
    void Go(db dis,db L)
    {
        if(OilBox.empty()) return;
        while(!OilBox.empty() && dis>OilBox.begin()->cap*L)
        {
            dis-=OilBox.begin()->cap*L;
            Box_now-=OilBox.begin()->cap;
            OilBox.erase(OilBox.begin());
        }
        if(OilBox.empty()) { Box_now=0; return; }
        db use=dis/L;
        if(use>OilBox.begin()->cap) use=OilBox.begin()->cap;
        if(use<0) use=0;
        OilBox.begin()->cap-=use;
        Box_now-=use;
    }
    void Add(const Station &vir)
    {
        if(OilBox.empty())
        {
            OilBox.push_back(Oil(Box_sum-Box_now,vir.value));
            cost += (Box_sum-Box_now)*vir.value;
            Box_now = Box_sum;
            return;
        }
        check();
        db _value = vir.value;
        for(int i = 0;i<(int)OilBox.size();++i)
        {
            if(_value>OilBox[i].value) continue;
            for(int j = i;j<(int)OilBox.size();++j)
            {
                Box_now-=OilBox[j].cap;
                cost -= OilBox[j].cap*OilBox[j].value;
            }
            OilBox.resize(i);
            break;
        }
        OilBox.push_back(Oil(Box_sum-Box_now,vir.value));
        cost += (Box_sum-Box_now)*vir.value;
        Box_now = Box_sum;
        check();
    }
};
void EX()
{
    cout << "No Solution" << endl;
    exit(0);
}
int main()
{
    double S,C,L,P0;
    int N;
    cin >> S >> C >> L >> P0 >> N;
    vector<Station> arr;
    arr.push_back(Station(0,P0));
    for(int i = 0;i<N;i++)
    {
        Station tmp;
        cin >> tmp.dis >> tmp.value;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end(),[](const Station &a,const Station &b){return a.dis<b.dis;});
    arr.push_back(Station(S,0));
    Car self(C);
    db dis_now = 0;
    for(const Station &now:arr)
    {
        if(now.dis-dis_now>self.Box_sum*L+1e-9) EX();
        self.Go(now.dis-dis_now,L);
        self.Add(now);
        dis_now = now.dis;
    }
    cout << std::fixed << std::setprecision(2) << self.cost << endl;
    return 0;
}