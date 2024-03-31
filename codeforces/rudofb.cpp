#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int n) {
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] != 0 && arr[i]>0) {
            arr[i + 1] = arr[i + 1] - 2 * arr[i];
            arr[i + 2] = arr[i + 2] - arr[i];
            arr[i] = 0;
        }
      else if(arr[i]<0)
      {
        return false;
      }
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0 || arr[i]>0) {
            return false;
        }
    }
    return true;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (check(arr, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
