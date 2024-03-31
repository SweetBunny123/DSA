#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long map_count = 0, pie_count = 0, mapie_count = 0;

        for (int i = 0; i < n - 2; i++) {
            if (s.substr(i, 3) == "map")
            { 
              map_count++;
              if(i<n-4 && s.substr(i,5)=="mapie")mapie_count++;
            } 
            else if (s.substr(i, 3) == "pie")
                pie_count++;
        }

        long long min_deletions = map_count + pie_count - mapie_count;
        cout << min_deletions << endl;
    }

    return 0;
}
