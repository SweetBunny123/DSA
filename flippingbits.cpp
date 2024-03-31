#include<bits/stdc++.h>
using namespace std;
void flipbits(vector<int>&tree, int a,int b, int l, int r, int node)
{
  if(a==b && a>=l && b<= r)
  {
    tree[node] = !tree[node];
  }
  if(a>b || a>r || b<l)
  {
    return;
  }
  if(a>=l && b<=r)
  {
    tree[node] = !tree[node];
    return;
  }
  flipbits(tree, a, (a+b)/2, l, r,2*node+1);
  flipbits(tree, 1+(a+b)/2, b, l, r, 2*node+2);
  return;
}

int query(vector<int>&tree, vector<int>&arr, int n, int i )
{
  int j = i; 
  i = n-1+i;
  int x = 0;
  while(i>-1)
    {
      x = x^tree[i];
      if(i==0) break;
      i = (i-1)/2;
    }
  if(x) return !arr[j];
  else return arr[j];
}

int main()
{
  vector<int>arr = {0,1,0,1,1,0,0,1,0};
  int n=1;
  while(n<arr.size())n*=2;
  vector<int>tree(2*n-1,0);
  flipbits(tree, 0, n-1, 0, 4, 0);
  for(int i = 0; i<arr.size(); i++)
    {
      cout<<query(tree, arr, n, i)<<" ";
    }
  return 0;
}