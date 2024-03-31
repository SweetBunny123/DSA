#include<bits/stdc++.h>
using namespace std;

// Function to count pairs of denominations
int countPairs(int n, int m, int k, vector<int>& left_denominations, vector<int>& right_denominations) {
    // Sort both arrays
    sort(left_denominations.begin(), left_denominations.end());
    sort(right_denominations.begin(), right_denominations.end());

    // Initialize count
    int count = 0;

    // Iterate through all pairs of denominations
    for (int left : left_denominations) {
        for (int right : right_denominations) {
            if (left + right <= k) {
                count++;
            } else {
                break; // Since the array is sorted, no need to check further
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    // Iterate through each test case
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        // Read inputs for each test case
        vector<int> left_denominations(n);
        vector<int> right_denominations(m);

        for (int i = 0; i < n; i++) {
            cin >> left_denominations[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> right_denominations[i];
        }

        // Call function to count pairs of denominations
        int result = countPairs(n, m, k, left_denominations, right_denominations);

        // Output the result for the current test case
        cout << result << endl;
    }

    return 0;
}
