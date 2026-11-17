#include <iostream> 
using namespace std;int main(){int x,n;cin >> x >> n;int ans = 0;while(n--){if(x%7!=0&&x%7!=6) ans+=250;x++;}cout << ans << endl;return 0;}