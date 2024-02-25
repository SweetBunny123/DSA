#include <unordered_map>

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> arr;

        for (auto& trip : trips) {
            arr[trip[1]] += trip[0];
            arr[trip[2]] -= trip[0];
        }  

        int sum = 0; 

        for (const auto& entry : arr) {
            sum += entry.second;
            if(sum>capacity)return false;
        }
        return true;
    }
};
