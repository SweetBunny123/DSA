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

        vector<pair<char, int>> p(26); // Initialize the pair with all characters and 0
        for (int i = 0; i < 26; i++) {
            p[i] = make_pair('a' + i, 0);
        }

        vector<char> ans(n);

        for(int i = 0; i < n; i++) {
          for(int j=0; i<26; i++)
            {
              if(arr[i]==p[j].second)
                ans[i]=p[j].first;
                p[j].second++;
            } // Increment the count
        }

        for(int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
