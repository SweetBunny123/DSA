#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>&nums)
{
    stack<int>s;
    vector<int>ans(nums.size(),-1);
    for(int i = nums.size()-1; i>=0; i--)
      {
        
        while(!s.empty() && s.top()<=nums[i])
          {
            s.pop();
          }
        if(!s.empty())
        {
          ans[i] = s.top();
        }
        s.push(nums[i]);
      }
  return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
      {
        cin>>arr[i];
      }
    cout<<endl;
    vector<int> ans = nextGreaterElement(arr);
  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}