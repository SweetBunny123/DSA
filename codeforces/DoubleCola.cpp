#include <bits/stdc++.h>
using namespace std;

int main() {
    int number;
    cin >> number;
    int multiplier = 1;
    while(multiplier*5< number)
    {
        number -=5*multiplier;
        multiplier *= 2;

    }

    string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << names[(number - 1) / multiplier] << endl;

    return 0;
}
