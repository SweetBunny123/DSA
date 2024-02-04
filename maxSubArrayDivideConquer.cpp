#include <bits/stdc++.h>
using namespace std;

int maxcrossingarraysum(vector<int>& arr, int low, int mid, int high) {
    int maxr = INT_MIN;
    int maxl = INT_MIN;
    int rsum = 0, lsum = 0;

    for (int i = mid; i >= low; i--) {
        lsum += arr[i];
        maxl = max(maxl, lsum);
    }

    rsum = 0;
    for (int i = mid + 1; i <= high; i++) {
        rsum += arr[i];
        maxr = max(maxr, rsum);
    }

    return maxl + maxr;
}

int maxarraysum(vector<int>& arr, int l, int r) {
    if (l == r) {
        return arr[l];
    } else {
        int mid = l + (r - l) / 2;
        int left = maxarraysum(arr, l, mid);
        int right = maxarraysum(arr, mid + 1, r);
        int center = maxcrossingarraysum(arr, l, mid, r);
        return max(max(left, right), center);
    }
}

int main() {
    vector<int> arr = {1, -3, 4, -2, -1, 6};
    int n = arr.size();
    int max_sum = maxarraysum(arr, 0, n - 1);
    cout << "Maximum subarray sum is " << max_sum << endl;
    return 0;
}
