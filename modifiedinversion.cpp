#include <bits/stdc++.h>
using namespace std;

long long merge(vector<long long> &arr, long long left, long long mid, long long right, long long a, long long b) {
    long long i = left, j = mid + 1;
    vector<long long> result;
    long long count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <arr[j] * a + b) {
            count += right - j + 1;
            i++;
        } else {
            j++;
        }
    }
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            result.push_back(arr[i]);
            i++;
        } else {
            result.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        result.push_back(arr[j]);
        j++;
    }

    for (long long i = left; i <= right; i++) {
        arr[i] = result[i - left];
    }
    return count;
}

long long mergesort(vector<long long> &arr, long long left, long long right, long long a, long long b) {
    long long count = 0;
    if (left < right) {
        long long mid = left + (right - left) / 2;
        count += mergesort(arr, left, mid, a, b);
        count += mergesort(arr, mid + 1, right, a, b);
        count += merge(arr, left, mid, right, a, b);
    }
    return count;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        long long result;
        long long n, a, b;
        cin >> n >> a >> b;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        result = mergesort(arr, 0, n - 1, a, b);
        cout << result << endl;
    }
    return 0;
}
