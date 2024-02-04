#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += log2(arr[i]); // Not sure about the usage of log2() here
        }
        int k = n - count;
        int count2 = 0; // Missing semicolon
        if(k <= 0) {
            cout << -1 << endl;
        } else {
            for(int i = n; i >= 1 && k > 0; i--) { // Corrected loop condition
                k -= log2(n); // Not sure about the usage of log2() here
                i--;
                count2++;
            }
            cout << count2 << endl;
        }
    }
    return 0;
}
  