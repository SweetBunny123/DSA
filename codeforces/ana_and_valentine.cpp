#include<bits/stdc++.h>
#include <string>
using namespace std;
int count_trailing_zeros(int num) {
    string str = to_string(num);
    int count = 0;
    for (int i = str.length() - 1; i > 0; i--) {
        if (str[i] == '0')
            count++;
        else
            break; // Stop counting if non-zero digit encountered
    }
    return count;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, m;
        cin>>n>>m;
        vector<int>s(n);
        for(int i = 0; i<n; i++)
        {
            cin>>s[i];
        }
        vector<int>arr;
        int total = 0;
        for(int i = 0; i<n; i++)
        {
            arr.push_back(count_trailing_zeros(s[i]));
            total += to_string(s[i]).length();
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int sub = 0;
        for(int i =0; i<n; i++)
        {
            if(i%2==0)
            {
                sub+=arr[i];
            }
        }
        if(total-sub>=m+1)
        {
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Anna"<<endl;
        }
    }
    return 0;
}