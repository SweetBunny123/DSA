#include <bits/stdc++.h>
using namespace std;

void update_binary_index_tree(int i, vector<int>& bit, int x) {
    while (i < bit.size()) {
        bit[i] += x;
        i += i & (-i);
    }
}

int prefix_sum_usingbit(int i, vector<int>& bit) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}

int main() {
    // Example usage
    vector<int> arr = {0, 1, 2, 3, 4, 5};
    vector<int> bit(arr.size() + 1, 0); 
    for (int i = 1; i <= arr.size(); ++i) {
        update_binary_index_tree(i, bit, arr[i - 1]);
    }
    for(int i = 0;i< bit.size() ; i++)
      {
        cout<<bit[i]<<" ";
      }
    cout<<endl;
    int index_to_update = 3;
    int value_to_add = 5;
    int original_value = arr[index_to_update - 1];
    update_binary_index_tree(index_to_update, bit, value_to_add - original_value);
    arr[index_to_update - 1] = value_to_add;
    for(int i = 0;i< bit.size() ; i++)
      {
        cout<<bit[i]<<" ";
      }
    cout<<endl;
    int prefix_sum_index = 4;
    int prefix_sum = prefix_sum_usingbit(prefix_sum_index, bit);
    cout << "Prefix sum up to index " << prefix_sum_index << " is: " << prefix_sum << endl;

    return 0;
}
void update(int l, int r, vector<int>& bit, int x)
{
  update_binary_index_tree(bit, l, x);
  update_binary_index_tree(bit, r+1, -x);
}
