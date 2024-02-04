#include<bits/stdc++.h>
using namespace std;
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
      long long n, k;
      cin>>n>>k;
      long long gcd;
      for(long long i = k; i<=n; i++)
        {
          if(n%i==0)
          {
            gcd = n/i;
            break;
          }
        }
      cout<<gcd<<endl;
    }
  return 0;
}