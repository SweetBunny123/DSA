#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int left = 0; 
        int right = arr.size() - 1;
        int mini = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[right]) {
                mini = min(arr[mid], mini);
                right = mid - 1;
            } else {
                mini = min(arr[left], mini);
                left = mid + 1;
            }
        }
        return mini;
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {3, 4, 5, 1, 2};
    vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> arr3 = {1, 2, 3};
    vector<int> arr4 = {3, 1, 2};

    cout << "Minimum element in arr1: " << solution.findMin(arr1) << endl;
    cout << "Minimum element in arr2: " << solution.findMin(arr2) << endl;
    cout << "Minimum element in arr3: " << solution.findMin(arr3) << endl;
    cout << "Minimum element in arr4: " << solution.findMin(arr4) << endl;

    return 0;
}
