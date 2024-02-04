#include<bits/stdc++.h>
using namespace std;
int maxarraysum(vector<int>arr)
{
  int sum = 0; int maxSum = INT_MIN;
  for(int i = 0; i<arr.size(); i++)
    {
      sum += arr[i];
      maxSum = max(maxSum, sum);
      if(sum<0)
      {
        sum = 0;
      }
      
    }
  return maxSum;
}
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        int sum = 0;
        int oddsum =0;
        int evensum = 0;
        for(int i = 0; i<n; i++)
          {

            cin>>arr[i];
            if(i%2==0)
            {
              sum+=arr[i];
            }
          }
        vector<int>even;
        vector<int>odd;
        for(int i= i; i<n; i+=2)
          {
            even.push_back(arr[i]-arr[i-1]);
          }
        for(int i = 2; i<n; i+=2)
          {
            odd.push_back(arr[i]-arr[i-1]);
          }
        cout<<sum<<endl;
        evensum = maxarraysum(even);
        oddsum = maxarraysum(odd);
        sum+= max(evensum, oddsum);
      cout<<sum<<endl;
    }
}