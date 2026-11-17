#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

typedef unsigned long long LL;
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    if (!(cin >> n)) return 0;
    multiset<LL> arr;
    for (LL i = 0; i < n; i++) {
        LL val;
        cin >> val;
        arr.insert(val);
    }
    LL ans_FJ = 0, ans_BE = 0;
    bool is_FJ_turn = true;
    while (!arr.empty())
    {
        LL current_score = is_FJ_turn ? ans_FJ : ans_BE;
        LL chosen_val = 0;
        bool found = false;
        auto it = arr.upper_bound(current_score);
        if (it != arr.begin()) {
            --it;
            chosen_val = *it;
            arr.erase(it); 
            found = true;
        }
        if (!found) {
            chosen_val = *arr.begin();
            arr.erase(arr.begin());
        }

        if (is_FJ_turn) {
            ans_FJ += chosen_val;
        } else {
            ans_BE += chosen_val;
        }
        is_FJ_turn = !is_FJ_turn;
    }

    cout << ans_FJ << ' ' << ans_BE << endl;
    return 0;
}