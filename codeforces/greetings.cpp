#include<bits/stdc++.h>
using namespace std;
int merge(vector<pair<int,int>>& a, int left, int mid, int right) {
    int count = 0;
    int i = left;
    int j = mid + 1;
    vector<pair<int,int>> result;

    while (i <= mid && j <= right) {
        if (a[i].second > a[j].second) {
            count += (right - j + 1);
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back(a[i]);
        i++;
    }
    while (j <= right) {
        result.push_back(a[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        a[k] = result[k - left];
    }

    return count;
}

int mergesort(vector<pair<int, int>>&arr, int l, int r)
{
  int count = 0;
  if(l<r)
  {
  
    int mid = l+(r-l)/2;
    count+=mergesort(arr,l,mid);
    count+=mergesort(arr,mid+1,r);
    count+=merge(arr,l,mid,r);
  }
  return count;
  
}
int main()
{
  int tc;
  cin>>tc;
  while(tc--)
    {
      int n;
      cin>>n;
      int count = 0;
      vector<pair<int, int>>arr(n);
      for(int i = 0; i<n; i++)
        {
          int a; int b;
          cin>>a>>b;
          arr[i] = {a,b};
        }
      sort(arr.begin(),arr.end());
      count = mergesort(arr,0,n-1);
      cout<<count<<endl;
    }
}