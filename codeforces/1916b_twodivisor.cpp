#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long a, b;
        cin>>a>>b;
        long long x = (a*b)/gcd(a,b);
        if(x!= a && x!=b)
        {
            cout<<x<<endl;
        }
        else
        {
            long long val = x;
            cout<<x*(b/a)<<endl;
        }
    }
    return 0;
}