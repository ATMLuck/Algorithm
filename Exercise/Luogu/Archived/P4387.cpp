#include "iostream"
#include "vector"
#include "stack"
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> pushed(n), poped(n);
        for (int &x : pushed) cin >> x;
        for (int &x : poped) cin >> x;

        stack<int> st;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == poped[j])
            {
                st.pop();
                j++;
            }
        }
        cout << (st.empty() ? "Yes" : "No") << '\n';
    }
    return 0;
}