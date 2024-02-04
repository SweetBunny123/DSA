#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        int j = n - 1;
        long long sum = 0; // Change to long long
        int i = n - 1;
        vector<long long> result(n, -1); // Change to long long
        while (i >= 0) {
            if (s[i] == '0') {
                j--;
                sum += j - i + 1;
                result[n - j - 2] = sum;
            }
            i--;
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
