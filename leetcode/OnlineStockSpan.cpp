#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> stk;

    StockSpanner() {

    }

    int next(int price) {
        int count = 1;
        while (!stk.empty() && stk.top().first <= price) {
            count += stk.top().second;
            stk.pop();
        }
        stk.push({price, count});
        return count;
    }
};

