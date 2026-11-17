#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> K(n);
    for (int i = 0; i < n; i++) cin >> K[i];

    vector<int> dist(n, -1);
    queue<int> q;
    dist[a - 1] = 0;
    q.push(a - 1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == b - 1) break;

        for (int dir : {1, -1}) {
            int nxt = cur + dir * K[cur];
            if (nxt >= 0 && nxt < n && dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    cout << dist[b - 1] << endl;
    return 0;
}