#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    unordered_map<int, int> count;
    int ans = 0, l = 0, r = 0;

    while (r < n) {
        ++count[arr[r]];
        while (count[arr[r]] > k) {
            --count[arr[l++]];
        }
        ans = max(ans, r - l + 1);
        ++r;
    }

    cout << ans << endl;
    return 0;
}
