#include <bits/stdc++.h>
using namespace std;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void permutation(int n, int k, set<int>& nums, string& str) {
    if (n == 0) return;

    int val;

    if (k <= 1 || k <= fact[n - 1]) {
        val = k == 0 ? *nums.rbegin() : *nums.begin();
    } else {
        int index = k / fact[n - 1];
        k = k % fact[n - 1];

        if (k == 0) index--;

        val = *next(nums.begin(), index);
    }

    str += to_string(val);
    nums.erase(val);

    permutation(n - 1, k, nums, str);
}

string getPermutation(int n, int k) {
    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(i);

    string str = "";
    permutation(n, k, nums, str);

    return str;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        string kth_perm_seq = getPermutation(n, k);
        cout << kth_perm_seq << endl;
    }

    return 0;
}
