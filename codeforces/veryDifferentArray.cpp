#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n); // Change to long long
        vector<long long> b(m); // Change to long long
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int abegin = 0;
        int aend = n - 1;
        int bbegin = 0;
        int bend = m - 1;
        while (i < n) {
            if (abs(a[abegin] - b[bend]) > abs(a[aend] - b[bbegin])) {
                sum += abs(a[abegin] - b[bend]);
                abegin++;
                bend--;
            } else {
                sum += abs(a[aend] - b[bbegin]);
                bbegin++;
                aend--;
            }
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}
