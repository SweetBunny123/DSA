#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0; 
        int j = 0;
        int count = 0;
        int max_len = 0; // Initialize max_len
        while(j < nums.size()) {
            if(nums[j] == 0) {
                count++;
            }
            j++;
            max_len = max(max_len, j - i); // Correct max_len calculation
            if(count < k) {
                count = 0;
                i = j;
            }
        }
        return max_len; // Return the calculated max_len
    }
};

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    Solution solution; // Create an instance of the Solution class
    int result = solution.longestOnes(nums, k); // Call the longestOnes function

    cout << "Length of the longest subarray with at most " << k << " zeros: " << result << endl;

    return 0;
}
