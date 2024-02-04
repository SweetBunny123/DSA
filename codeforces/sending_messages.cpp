#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        int flag = 0;
        long long f, a, b;
        cin >> n >> f >> a >> b;
        long long prev = 0;
        while(n--)
        {
            long long current;
            cin>>current;

            long long loss_on = (current-prev)*a;
            long long loss_off = b;
            long long actual = min(loss_off, loss_on);
            f-=actual;
            prev = current;
        }
        if(f>0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
