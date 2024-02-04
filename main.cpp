#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    long long n;
    long long h;
    cin >> n >> h;
    vector<long long> a;
    long long ma = LLONG_MIN;

    for (long long i = 0; i < n; i++)
    {
        long long k;
        cin >> k;
        ma = max(ma, k);
        a.push_back(k);
    }

    long long left = 1; // Starting from the minimum value
    long long right = ma; // Starting with the maximum value
    
    while (left < right)
    {
        long long mid = left + (right - left) / 2;

        long long sum = 0;
      
        for (long long j = 0; j < n; j++)
        {
            sum += (a[j] + mid - 1) / mid; // Ceiling division
        }

        if (sum > h)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        
      
    }

    cout << left << endl;

    return 0;
}
