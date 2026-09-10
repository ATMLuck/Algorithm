#include "iostream"
#include "string"
using namespace std;
string output(string& vir,int bugin,int end)
{
    string head,body,tile,value;
    int m_head = bugin,m_tile = end;
    while(vir[m_head]!='['&&m_head<m_tile)
    {
        head += vir[m_head];
        m_head++;
    }
    while(vir[m_tile]!=']'&&m_tile>=m_head)
    {
        tile = vir[m_tile] + tile;
        m_tile--;
    }
    if(m_head<vir.size()-1) m_head++;
    while(vir[m_head]<'9'&&vir[m_head]>'0')
    {
        value += vir[m_head];
        m_head++;
    }
    int k;
    if(value!="") k = stoi(value);
    else k = 0;
    cout << k;
    for(int i = 0;i<k;i++)
    {
        body=output(vir,m_head,m_tile-1);
    }
    return head+body+tile;
}
int main()
{
    string data;
    cin >> data;
    cout << output(data,0,data.size());
    return 0;
}