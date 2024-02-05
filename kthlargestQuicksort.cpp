#include<bits/stdc++.h>
using namespace std;
int find_rank(vector<int>&arr, int low, int high, int rank);
int good_pivot(vector<int> &A,int left,int right);
int partition(vector<int>& arr, int low, int high) {
    int pivot = good_pivot(arr,low,high);
    swap(arr[pivot], arr[high]);
    pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
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
int find_rank(vector<int>& arr, int low, int high, int rank) {
    if (low < high) {
        int k = partition(arr, low, high);
        int rank_at_k = high - k + 1;

        if (rank == rank_at_k) {
            return arr[k];
        } else if (rank < rank_at_k) {
            return find_rank(arr, k + 1, high, rank);
        } else {
            return find_rank(arr, low, k - 1, rank - rank_at_k);
        }
    } else if (low == high) {
        if (rank == 1) {
            return arr[low];
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;
    int rank = find_rank(arr, 0, arr.size() - 1, k);
    cout << "Rank " << k << " element is: " << rank << endl;
    return 0;
}
