#include<bits/stdc++.h>
using namespace std;
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
      int n;
      cin>>n;
      vector<long long>arr(n);
      for(int i=0; i<n; i++)cin>>arr[i];
      long long ans = 0;
      map<long long, long long>mp;
      mp[arr[n-1]]++;
      for(int i = n-2; i>=0; i--)
      {
        if(mp[arr[i]])
        {
          ans += (i+1)*mp[arr[i]];
          mp[arr[i]] = mp[arr[i]]+(n-i);
        }
        else
        {
          mp[arr[i]] = mp[arr[i]]+(n-i);
        }
      }
      cout<<ans<<endl;

    }
  return 0;
}