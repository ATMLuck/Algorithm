#include <cstdio>
#include <queue>
using ull=unsigned long long;
using namespace std;
namespace FastIO {
    constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    int idx = 0, len = 0;

    inline int readChar() {
        if (idx == len) {
            len = (int)fread(buf, 1, BUF_SIZE, stdin);
            idx = 0;
            if (len == 0) return EOF;
        }
        return buf[idx++];
    }

    inline int readInt() {
        int c = readChar();
        while (c != '-' && (c < '0' || c > '9')) c = readChar();
        bool neg = (c == '-');
        if (neg) c = readChar();
        int x = 0;
        while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = readChar(); }
        return neg ? -x : x;
    }
}
int main()
{
    ull n;
    //scanf("%llu",&n);
    n = FastIO::readInt();
    vector<ull> tong(100001,0);
    for(ull i = 0;i<n;i++)
    {
        ull vir;
        //scanf("%llu",&vir);
        vir = FastIO::readInt();
        tong[vir]++;
    }
    queue<ull> arr;
    for(int i = 0;i<100001;i++)
    {
        for(ull j = 0;j<tong[i];j++) arr.push(i);
    }
    queue<ull> brr;
    ull ans = 0;
    ull vir[2];
    for(ull i = 0;i<n-1;i++)
    {
        for(int j = 0;j<2;j++)
        {
            if(arr.empty()) {vir[j] = brr.front();brr.pop();}
            else if(brr.empty()) {vir[j] = arr.front();arr.pop();}
            else 
            {
                if(arr.front()<brr.front())
                {
                    vir[j] = arr.front();
                    arr.pop();
                }
                else 
                {
                    vir[j] = brr.front();
                    brr.pop();
                }
            }
        }
        ans += vir[0]+vir[1];
        brr.push(vir[0]+vir[1]); 
    }
    printf("%llu",ans);
    return 0;
}