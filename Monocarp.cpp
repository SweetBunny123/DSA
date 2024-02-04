#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> result; // Changed vector type to int
    while (n > 0)
    {
        int m, k, a1, ak; // Changed variable types to int
        cin >> m >> k >> a1 >> ak;
        int x = m / k;
        int y = m % k;
        int k_coins_fancy = max(0, x - ak);
        int one_coins_fancy = max(0, y - a1);
        int k_coins_normal_remainng = max(0, ak - x);
        int one_coins_normal_remainng = max(0, a1 - y);
        int kol = min(k_coins_fancy, one_coins_normal_remainng / k);
        result.push_back(k_coins_fancy + one_coins_fancy - kol);
        n--;
    }

    // Print the results
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
