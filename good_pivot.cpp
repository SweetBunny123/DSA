#include <bits/stdc++.h>
using namespace std;
int good_pivot(vector<int> &A, int l, int r);
int find_rank(vector<int> &A, int l, int r, int rank);
int Partition(vector<int> &a, int l, int r) {
  int i = l + 1;
  int j = r;
  while (i <= j) {
    while (i <= j && a[i] <= a[l])
      i++;
    while (a[j] > a[l])
      j--;
    if (i < j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  swap(a[i - 1], a[l]);
  return i - 1;
}

int find_rank(vector<int> &A, int l, int r, int rank) {
  if (l < r) {
    int p = good_pivot(A, l, r);
    swap(A[p], A[l]);
    int k = Partition(A, l, r);
    if (rank == (r - k + 1)) {
      return k;
    } else if (rank < (r - k + 1)) {
      return find_rank(A, k + 1, r, rank);
    } else {
      return find_rank(A, l, k - 1, rank - (r - k + 1));
    }
  }
  return r;
}
int good_pivot(vector<int> &A, int l, int r) {
  int m = (r - l + 1) / 5;
  int i = l;
  int j = l;
  if (m > 1) {
    while (i + 4 <= r) {
      sort(A.begin() + i, A.begin() + i + 4);
      swap(A[j], A[i + 2]);
      ++j;
      i += 5;
    }
    return find_rank(A, l, l + m - 1, m / 2);
  }
  return l;
}
int main() {
  vector<int> A = {3, 99, 1, 100};
  cout << A[find_rank(A, 0, A.size() - 1, 2)];
}