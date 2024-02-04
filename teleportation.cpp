#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> result;  // Change vector<int> to vector<long long>
    long long no_of_testcases; // Change int to long long
    cin>>no_of_testcases;
    while (no_of_testcases)  // Fix: Initialize no_of_testcases before the loop
    {
        long long n;
        long long coins;
        cin >> n >> coins;
        vector<long long> array_with_money;  // Change vector<int> to vector<long long>

        for (long long i = 1; i <= n; i++)  // Change int to long long
        {
            long long money;  // Change int to long long
            cin >> money;
            array_with_money.push_back(money + i);
        }

        sort(array_with_money.begin(), array_with_money.end());  // Fix: Remove extra ')'

        long long count = 0;  // Change int to long long
        for (long long i = 0; i < n; i++)  // Change int to long long
        {
            if (array_with_money[i] <= coins)
            {
                count++;
                coins -= array_with_money[i];
                if(coins <= 0)
                {
                  break;
                }
            }
        }

        result.push_back(count);
        no_of_testcases--;
    }

    for (long long i = 0; i < result.size(); i++)  // Change int to long long
    {
        cout << result[i] << endl;
    }

    return 0;
}
