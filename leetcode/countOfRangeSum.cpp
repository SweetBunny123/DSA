#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    //this funciton works like binary search , it returns the highest index where a number is smaller than
    int bs(long long sum, vector<long long>& pre) {
        int lo = 0, hi = pre.size();

        while (lo < hi) {
            int mid = (lo + hi) >> 1;

            if (pre[mid] > sum) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
    // this function is for updating the binary indexed tree with an incrememnet value
    void update(vector<int>& bit, int idx, int inc) {
        for (++idx; idx < bit.size(); idx += idx & -idx) {
            bit[idx] += inc;
        }
    }
    // this if for calculating the sum uptill a given index
    int bitsum(vector<int>& bit, int idx) {
        int ans = 0;

        for (++idx; idx > 0; idx -= idx & -idx) {
            ans += bit[idx];
        }

        return ans;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int ans = 0;
        vector<long long> pre(n + 1, 0);
        //made a prefix sum array of n+1 size so that any index i will represent prefix sum till that index in the array
        for (int i = 0; i < n; i++) {
            pre[i + 1] = nums[i] + pre[i];
        }
        //sort the prefix sum so that we can carry out the binary search operation in it
        sort(pre.begin(), pre.end());
        // since bit is 1 based indexing we are making it of sized n+2;so that it can accomodate both 0 and n;

        vector<int> bit(n+5, 0);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            update(bit, bs(sum, pre), 1);
            sum += nums[i];
            //total count = total number of frequences that satisfies sum-lower minus total number of frequences = sum-upper;
            ans += bitsum(bit, bs(sum - lower, pre)) - bitsum(bit, bs(sum - upper - 1, pre));
        }

        return ans;
    }

};
