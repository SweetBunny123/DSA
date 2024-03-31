#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }
        long long ans = arr[0]-1;
        for(int i = 0; i<n-1; i++)
        {
            if(arr[i]<arr[i+1])ans+= arr[i+1]-arr[i];
        }
        cout<<ans<<endl;

    }
    return 0;
}
