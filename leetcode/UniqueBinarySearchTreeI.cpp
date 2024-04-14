#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate total number of binary trees using Catalan numbers
    unsigned long long numTrees(int n) {
        if (n <= 1) return 1;

        // Calculate Catalan number
        unsigned long long catalan = 1;
        for (int i = 0; i < n; ++i) {
            catalan *= (2 * n - i);
            catalan /= (i + 1);
        }

        return catalan / (n + 1);
    }
};
