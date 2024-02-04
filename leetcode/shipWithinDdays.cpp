#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int n, int days, int capacity) {
    int day_count = 1; // Start with 1 as we start counting from day 1
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > capacity) {
            day_count++;
            sum = arr[i]; // Reset the sum for the new day
        }
    }
    return day_count <= days;
}

int main() {
    int n, days;
    cin >> n >> days;
    vector<int> arr(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    int left = maxi; // Start with the capacity of the largest item
    int right = accumulate(arr.begin(), arr.end(), 0); // Maximum possible capacity is the sum of all items
    int ans = -1; // Initialize ans with an invalid value

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(arr, n, days, mid)) {
            ans = mid;
            right = mid - 1; // Reduce the capacity to find a possible smaller one
        } else {
            left = mid + 1; // Increase the capacity to find a possible larger one
        }
    }

    cout << ans << endl;
    return 0;
}
