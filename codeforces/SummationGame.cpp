#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m, k, x;
        cin >> m >> k >> x;

        vector<int> arr(m + 1, 0), pre_sum(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            cin >> arr[i];
        }

        sort(arr.begin() + 1, arr.end());

        for (int i = 1; i <= m; i++) {
            pre_sum[i] = pre_sum[i - 1] + arr[i];
        }

        int ans = INT_MIN;
        for (int i = m; i >= m - k; i--) {
            int r = min(i, x);
            ans = max(ans, 2 * (pre_sum[i-r]) - pre_sum[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
