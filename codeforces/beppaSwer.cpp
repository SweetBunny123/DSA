#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        map<int, int> index;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            index[b[i]] = i; // Correctly insert elements into the map
        }

        int j = index[a[0]];
        int temp = j;
        int sum = j;
        for (int i = 0; i < n-1; i++) { // Iterate up to n - 1 to avoid accessing a[i+1] out of bounds
            if (index[a[i + 1]] > j) {
                index[b[j]] = -1;
                j = index[a[i + 1]];
            }
        }
        index[b[j]] = -1;
        j = temp+1;
        int flag = 0;
        int ultra = 0;
        // cout<<sum<<endl;
        while(j<n)
        {
            if(index[b[j]]!=-1)
                {
                    // cout<<b[j];
                    flag = 1;
                    ultra = 1;
                    // cout<<b[j]<<endl;
                    sum++;
                }
            else
            {
                flag++;
            }
            j++;
        }
        if(flag!=0 and ultra!=0)
        {
            sum+= flag;
        }
        cout << sum<< endl;
    }
    return 0;
}
