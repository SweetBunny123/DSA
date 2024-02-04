#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = random() % (high - low + 1) + low;
    swap(arr[pivot], arr[high]);
    pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
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
