class Solution {
public:
    int search(vector<int>& nums, int target) {
    int high = nums.size()-1;
    int low = 0;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(target==nums[mid])
        {
            return mid;
        }
        else
        {
            if(nums[mid]<=nums[high])
            {
                if(target<=nums[high] && target>nums[mid])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(target>=nums[low]&& nums[mid]>=target)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }

            }
        }
    }
    return -1;
    }
};