class Solution {
public:
    bool search(vector<int>& nums, int target) {
    bool result = false;
    int right = nums.size()-1;
    int left = 0;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid]== target)return true;
        if(nums[mid]==nums[right]&& nums[mid]==nums[left])
        {
            right--;
            left++;
            continue;
        }
        if(nums[mid]<=nums[right])
        {
            if(target<=nums[right]&& target>=nums[mid])left = mid+1;
            else right = mid-1;
        }
        else
        {
            if(target>=nums[left] && target<=nums[mid])right = mid-1;
            else left = mid+1;
        }
    }
    return result;     
    }
};