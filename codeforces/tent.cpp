#include <iostream>
using namespace std;

long long minTents(int a, int b, int c) {
    long long tents = a + (b / 3);
    if (b % 3 != 0) {
        int x = b % 3;
        if ((x + c )/ 3 == 0)
            return -1;
        else {
            tents += (x + c) / 3 + ((x + c) % 3 != 0); // Increment by 1 if there are remaining universals
        }
    } else {
        tents += c / 3 + (c % 3 != 0); // Increment by 1 if there are remaining universals
    }
    return tents;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << minTents(a, b, c) << endl;
    }
    return 0;
}
