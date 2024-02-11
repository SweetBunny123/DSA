#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        set<int> tempSet1, tempSet2;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            tempSet1.insert(num);
        }

        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            tempSet2.insert(num);
        }

        vector<int> tempVector1(tempSet1.begin(), tempSet1.end());
        vector<int> tempVector2(tempSet2.begin(), tempSet2.end());

        sort(tempVector1.begin(), tempVector1.end());
        sort(tempVector2.begin(), tempVector2.end());

        int ptrA = 0, ptrB = 0;
        int countA = 0, countB = 0;

        for (int j = 1; j <= k; j++) {
            if (ptrA < tempVector1.size() && tempVector1[ptrA] == j && (ptrB >= tempVector2.size() || tempVector2[ptrB] != j)) {
                countA++;
                ptrA++;
            } else if (ptrB < tempVector2.size() && tempVector2[ptrB] == j && (ptrA >= tempVector1.size() || tempVector1[ptrA] != j)) {
                countB++;
                ptrB++;
            } else if (ptrA < tempVector1.size() && ptrB < tempVector2.size() && tempVector1[ptrA] == j && tempVector2[ptrB] == j) {
                if (countA > countB) {
                    countB++;
                    ptrB++;
                    ptrA++;
                } else if(countA) {
                    countA++;
                    ptrA++;
                    ptrB++;
                }
            }
            if (countA > k / 2 || countB > k / 2) {
                cout << "NO\n";
                goto next_case;
            }
        }
        if (countA == k / 2 && countB == k / 2)
            cout << "YES\n";
        else
            cout << "NO\n";
        next_case:;
    }
    return 0;
}
