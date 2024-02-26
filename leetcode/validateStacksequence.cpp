class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        vector<int> stack;
        
        while (i < pushed.size() && j < popped.size()) {
            if (!stack.empty() && stack.back() == popped[j]) {
                stack.pop_back();
                j++;
            } else if (pushed[i] == popped[j]) {
                i++;
                j++;
            } else {
                stack.push_back(pushed[i]);
                i++;
            }
        }
        
        while (j < popped.size() && !stack.empty() && stack.back() == popped[j]) {
            stack.pop_back();
            j++;
        }
        
        return j == popped.size();
    }
};