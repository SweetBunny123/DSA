class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&nums1, vector<int>& nums2) {
        vector<int> stack;
        int n = nums2.size();
        vector<int>mp(10000, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && nums2[i] >stack.back()) {
                stack.pop_back();
            }
            if (!stack.empty()) {
                mp[nums2[i]] = stack.back();
            }
            stack.push_back(nums2[i]);
        }
        vector<int>answer2(nums1.size());
        for(int i = 0; i<nums1.size(); i++)
        {
            answer2[i] = mp[nums1[i]];
        }
        return answer2; 
    }
};
