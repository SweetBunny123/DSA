#include<bits/stdc++.h>
using namespace std;
int max_subarry_sum(vector<int>arr)
{
  int sum = 0; int maxSum = INT_MIN;
  for(int i = 0; i < arr.size(); i++)
    {
      sum += arr[i];
      maxSum = max(maxSum, sum);
      if(sum < 0)
      {
        sum = 0;
      }
    }
  return maxSum;
}
int main()
{
  vector<int>arr = {-2, -3, 4, -1, -2, 1, 5};
  int maxSum = max_subarry_sum(arr);
  cout << maxSum;
  return 0;
}