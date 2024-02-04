#include<bits/stdc++.h>
int maxcrossingarraysum(vector<int> &arr, int low, int mid, int high)
{
  maxr = INT_MIN;
  maxl = INT_MIN;
  for(int i = mid; i<high; i++)
    {
      rsum+=arr[i];
      maxr= max(maxr,rsum);
    }
  for(int j = mid-1; j>=0; j--)
    {
      lsum+=arr[j];
      maxl = max(maxl,lsum);
    }
  return maxl+maxr;
}

int maxarraysum(vector<int>&arr, int l, int r)
{
  if(l==r)
  {
    return arr[l];
  }
  else if(l>r)
  {
    return 0;
  }
  else
  {
    int mid = l+(r-l)/2;
    int left = maxarraysum(arr,l,mid);
    int right = maxarraysum(arr,mid+1,r);
    int center = maxcrossingarraysum(arr, l,mid,r);
    return max(left,max(right,center));
  }
}
int main()
{
  
}
