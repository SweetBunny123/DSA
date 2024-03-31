#include <bits/stdc++.h>
using namespace std;

void flip(vector<int>& tree, int a, int b, int l, int r, int node) {
  if(a==b && a >=l && b <= r) {
    tree[node] = !tree[node];
    return;
  }
  if(a>b || a>r || b<l) return;
  if(a >=l && b <= r){
    tree[node] = !tree[node];
    return;
  }
  flip(tree, a, (a+b)/2, l, r, 2*node+1);
  flip(tree, 1 + (a+b)/2, b, l, r, 2*node+2);
  return;
}

vector<int> build(vector<int>& arr) {
  int size = arr.size();
  int n = 1;
  while(n < size) n*=2;
  for(int i = size; i < n; i++) {
    arr.push_back(0);
  }
  vector<int> tree(2*n-1, 0);
  return tree;
}

int query(vector<int>& tree,vector<int>& arr, int n, int i) {
  int j = i;
  i = n-1 + i;
  int x = 0;
  while(i > -1) {
    x = x^tree[i];
    if(i==0) break;
    i = (i-1)/2;
  }
  if(x) return !arr[j];
  return arr[j];
}

int main() {
  vector<int> arr = {0,1,0,1,1,0,0,1,0};
  vector<int> tree = build(arr);
  int n = arr.size();
  flip(tree, 0, n-1, 0, 2, 0);
  for(int i = 0; i < n; i++) {
    cout << query(tree, arr, n, i) << " ";
  } cout << endl;
  flip(tree, 0, n-1, 0, 2, 0);
  for(int i = 0; i < n; i++) {
    cout << query(tree, arr, n, i) << " ";
  } cout << endl;

  return 0;
}