#include<bits/stdc++.h>
using namespace std;

void next(vector<int>&arr)
{
  int i = arr.size()-2;
  while(arr[i]>arr[i+1])i--;
  if(i==-1)reverse(arr.begin(),arr.end());
  else{
    int j = arr.size()-1;
    while(j>i)
      {
        if(arr[j]>arr[i])break;
        j--;
      }
    swap(arr[i],arr[j]);
    reverse(arr.begin()+i+1,arr.end());
  }
}
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
      int n,k;
      cin>>n>>k;
      vector<int>v(n);
      for(int i = 0;i<n;i++)
        {
         v[i] = i+1;
        }
      k--;
      while(k--)
        {
          next(v);
        }
      for(int i = 0;i<n;i++)
      {
        cout<<v[i]<<"";
      } 

    }
}