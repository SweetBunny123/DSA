#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  map<int,int>count;
  int result = 0;
  for(int i= 0; i<n; i++)
    {
    int x;
    cin>>x;
    arr[i] = x-i;
    count[arr[i]]++;
    }
  for(int i = 0; i<n; i++)
    {
      if(count[arr[i]]>1)
      {
        result+=(count[arr[i]]*(count[arr[i]]-1))/2;
        count[arr[i]] = 0;
      }
    }
  cout<<result<<endl;
  return 0;
}