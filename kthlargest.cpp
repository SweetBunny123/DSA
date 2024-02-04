#include <bits/stdc++.h>
using namespace std;

int main() {
        int k;
        long long n;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << arr[n - k] << endl;
    return 0;
}
