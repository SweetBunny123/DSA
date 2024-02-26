class Solution {
public:
    unordered_map<int, int> invalidValueCount;                  // lazy remove counter
    priority_queue<int> lowerHalf;                              // max heap
    priority_queue<int, vector<int>, greater<int>> upperHalf;   // min heap;
    int lowerSize = 0;  // count of valid numbers present in lowerHalf heap
    int upperSize = 0;  // count of valid numbers present in upperHalf heap

    // O(logk) time 
    void balanceHeaps() {
        // Make sure the heaps differ in size by max 1
        // Make sure lowerHalf is not empty to avoid incorrect placement for adding numbers
        if (lowerSize == upperSize) return;
        else if (lowerSize == 0 || upperSize > lowerSize + 1) {
            // lower half empty or upper half just to big
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
            ++lowerSize;
            --upperSize;
        }
        else if (lowerSize > upperSize + 1) {
            // lower half too big
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
            --lowerSize;
            ++upperSize;
        }    
    }

    // O(logk) time 
    void add(int num) {
        // Add to lower half by default or choose correct heap based on current middles
        // Update lower and upper halve sizes based on VALID number insertion
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
            ++lowerSize;
        }
        else {
            upperHalf.push(num);
            ++upperSize;
        }
        balanceHeaps();
    }

    // O(logk) time 
    void lazyRemove(int num) {
        ++invalidValueCount[num];

        // Update lower and upper halve sizes based on INVALID number removal
        if (num <= lowerHalf.top()) {
            --lowerSize;
        }
        else {
            --upperSize;
        }
        // Adjust the two heaps based on the newly updated VALID sizes
        balanceHeaps();

        // After rebalancing, remove any INVALID numbers that
        // appear at the top of either heap
        while (!lowerHalf.empty() && invalidValueCount[lowerHalf.top()] != 0) {
            --invalidValueCount[lowerHalf.top()];
            lowerHalf.pop();       
        }
        while (!upperHalf.empty() && invalidValueCount[upperHalf.top()] != 0) {
            --invalidValueCount[upperHalf.top()];
            upperHalf.pop();       
        }
    }

    // O(1) time
    double getMedian() {
        if (lowerSize == upperSize) return (lowerHalf.top() / 2.0) + (upperHalf.top() / 2.0);
        return lowerSize > upperSize ? lowerHalf.top() : upperHalf.top();
    }

    // O(nlogk) time | O(n + k) space
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        for (int r = 0; r < nums.size(); ++r) {
            int inputNum = nums[r];
            add(inputNum);
            if (r >= k) {
                int outputNum = nums[r - k];
                lazyRemove(outputNum);
            }
            if (r >= k - 1) {
                res.push_back(getMedian());
            }
        }
        return res;
    }
};