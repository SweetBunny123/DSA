class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v(20002, 0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                v[10000 + nums[i]]++;
            } else {
                v[abs(nums[i])]++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <=0) {
                if(v[abs(nums[i])]>0)minHeap.push(make_pair(v[abs(nums[i])], nums[i]));
                v[abs(nums[i])] = -1;
            } else {
                if(v[10000+(nums[i])]>0)
                minHeap.push(make_pair(v[10000 + nums[i]], nums[i]));
                v[10000+(nums[i])] = -1;
            }
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};