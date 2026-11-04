#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (b < 2) return 0;

  
    const int LIM = 3163;
    vector<int> sp;
    vector<bool> c(LIM + 1, false);
    for (int i = 2; i <= LIM; ++i) {
        if (!c[i]) {
            sp.push_back(i);
            for (long long j = 1LL * i * i; j <= LIM; j += i) c[(int)j] = true;
        }
    }
    auto isPrime = [&](int n) {
        if (n < 2) return false;
        for (int p : sp) {
            if (1LL * p * p > n) break;
            if (n % p == 0) return false;
        }
        return true;
    };

    string out;
    auto emit = [&](int x) { out += to_string(x); out += '\n'; };

    int small[] = {2, 3, 5, 7, 11};
    for (int x : small)
        if (x >= a && x <= b) emit(x);
    if (b <= 11) { cout << out; return 0; }

    static const int p10[8] = {1,10,100,1000,10000,100000,1000000,10000000};

    for (int len = 3; len <= 7; len += 2) {
        int half = (len + 1) / 2;
        for (int p = p10[half - 1]; p <= p10[half] - 1; ++p) { 
            int t = p / 10, rev = 0;
            while (t) { rev = rev * 10 + t % 10; t /= 10; }
            int pal = p * p10[half - 1] + rev;
            if (pal > b) { cout << out; return 0; }
            if (pal < a) continue;
            if (pal % 2 == 0 || pal % 5 == 0) continue;
            if (isPrime(pal)) emit(pal);
        }
    }
    cout << out;
    return 0;
}