class Solution {
public:
    long long merge(vector<int>& arr, int left, int mid, int right, int diff) {
        long long count = 0;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j] + diff) {
                count += right - j + 1;
                i++;
            } else {
                j++;
            }
        }

        i = left;
        j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= right) {
            if (arr[i] < arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }

        return count;
    }

    long long mergesort(vector<int>& nums, int left, int right, int diff) {
        long long count = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;
            count += mergesort(nums, left, mid, diff);
            count += mergesort(nums, mid + 1, right, diff);
            count += merge(nums, left, mid, right, diff);
        }

        return count;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> diffarr(nums1.size());

        for (int i = 0; i < nums1.size(); i++) {
            diffarr[i] = nums1[i] - nums2[i];
        }

        return mergesort(diffarr, 0, diffarr.size() - 1, diff);
    }
};