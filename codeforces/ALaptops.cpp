#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    vector<int> price;
    map<int, int> quality;

    while (tc--) {
        int p, q;
        cin >> p >> q;
        price.push_back(p);
        quality[p] = q;
    }

    sort(price.begin(), price.end());

    bool flag = false;
    for (int i = 0; i < price.size() - 1; i++) {
        if (quality[price[i]] > quality[price[i + 1]]) {
            cout << "Happy Alex";
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "Poor Alex";
    }

    return 0;
}
