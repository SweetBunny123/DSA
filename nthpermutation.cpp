#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string getPermutation(int n, int k) {
    vector<int> factorial(n, 1);
    for (int i = 1; i < n; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }

    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    string result;
    --k; // Convert k to 0-based indexing

    for (int i = n; i >= 1; --i) {
        int index = k / factorial[i - 1];
        k %= factorial[i - 1];
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
    }

    return result;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string kth_permutation = getPermutation(n, k);
        cout << kth_permutation << endl;
    }
    return 0;
}
