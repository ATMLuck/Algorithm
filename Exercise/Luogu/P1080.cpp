#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct Peo
{
    int left;
    int right;
};
void pop_sort(vector<Peo> &arr)
{
    int size = static_cast<int>(arr.size());
    for(int i = 1;i<size;i++)
    {
        for(int j = size-1;j>i;j--)
        {
            if (arr[j-1].left * arr[j-1].right > arr[j].left * arr[j].right)
                swap(arr[j], arr[j-1]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<Peo> arr(n+1);
    for(int i = 0;i<=n;i++)
        cin >> arr[i].left >> arr[i].right;
    pop_sort(arr);
    int tmp = arr[0].left,ans = -1;
    for(int i = 1;i<=n;i++)
    {
        int self = tmp/arr[i].right;
        ans = max(ans,self);
        tmp*=arr[i].left;
    }
    cout << ans << endl;
    return 0;
}
/*
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    arr = []
    idx = 1
    for _ in range(n + 1):
        left = int(data[idx])
        right = int(data[idx + 1])
        arr.append([left, right])
        idx += 2
    
    # 冒泡排序：对 arr[1..n] 按 left*right 升序排序（arr[0] 不参与）
    size = len(arr)
    for i in range(1, size):
        for j in range(size - 1, i, -1):
            if arr[j - 1][0] * arr[j - 1][1] > arr[j][0] * arr[j][1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
    
    tmp = arr[0][0]
    ans = -1
    for i in range(1, size):
        self_val = tmp // arr[i][1]
        if self_val > ans:
            ans = self_val
        tmp *= arr[i][0]
    
    print(ans)

if __name__ == "__main__":
    main()
*/