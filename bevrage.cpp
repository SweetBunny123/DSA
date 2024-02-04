#include <bits/stdc++.h>
using namespace std;

int main() {
    long long shops;
    cin >> shops;
    vector<long long> answer;
    vector<long long> price;

    for (int i = 0; i < shops; i++) {
        long long prices;
        cin >> prices;
        price.push_back(prices);
    }

    sort(price.begin(), price.end());

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long money;
        cin >> money;
        auto it = upper_bound(price.begin(), price.end(), money);
        answer.push_back(distance(price.begin(), it));
    }

    // Print the results
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
