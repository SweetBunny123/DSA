#include<bits/stdc++.h>
using namespace std;
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
  int start;
  int end;
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<char>arr(n);
  for(int i = 0; i<n; i++)
    {
      cin>>arr[i];
      
    }
  for(int i = 0; i<n; i++)
    {
      if(arr[i] == 'B')
        start = i;
        break;
    }
  for(int i = n-1; i>=0; i--)
    {
      if(arr[i] == 'B')
        end = i;
        break;
    if(start==end)
    {
      cout<<0<<endl;
    }
    else
    {
      cout<<end-start+1<<endl;
    }
    }
  }
  return 0;
}