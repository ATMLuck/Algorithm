#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long x = a, y = b, z = c;
    if (x > y) swap(x, y);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);
    
    long long numerator = x;
    long long denominator = z;
    
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    
    cout << numerator << "/" << denominator << endl;
    return 0;
}