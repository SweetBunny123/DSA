#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long value = 1; 
    const int MOD = 1000000007;

    int nCr(int n, int r) {
        vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, 0));

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, r); ++j) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[n][r];
    }

    void recursive__val(vector<int>& nums) {
        if(nums.size()<=1) return;

        vector<int>left; 
        vector<int>right;
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long count = nCr(nums.size()-1, min(left.size(), right.size()));
        value = (value * count) % MOD;
        recursive__val(left);
        recursive__val(right);
    }

    int numOfWays(vector<int>& nums) {
        recursive__val(nums);
        return (int)(value - 1);
    }
};
