class Solution {
public:
    vector<int> tree;
    int size;

    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];  // If second element is equal, sort by first element
        } else {
            return a[0] < b[0];  // Sort by second element in descending order
        }
    }

    void update_positions(int index, int val) {
        long long j = index;
        tree[j] = val;
        while (j > 0) {
            j = (j - 1) / 2;
            tree[j] = tree[2 * j + 1] + tree[2 * j + 2];
        }
    }

    int get_position(int people_before, int node, int start, int end) {
        if (start == end) {
            return start; 
        }
        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        if (people_before <= tree[left]) {
            return get_position(people_before, left, start, mid);
        } else {
            return get_position(people_before - tree[left], right, mid + 1, end);
        }
    }

    vector<int> get_positions(vector<vector<int>>& sorted_people) {
        int n = 1;
        while (n <= sorted_people.size()) n *= 2;
        size = n;
        tree.assign(2 * n + 2, 0);
        vector<int> positions;

        // Initialize leaf nodes with 1 for each person
        for (int i = 0; i < sorted_people.size(); i++) {
            update_positions(size - 1 + i, 1);
        }

        for (int i = 0; i < sorted_people.size(); i++) {
            int pos = get_position(sorted_people[i][1] + 1, 0, 0, size - 1); // Get position based on k value
            positions.push_back(pos);
            update_positions(size - 1 + pos, 0); // Update positions based on k value
        }

        return positions;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), customComparator);
        vector<vector<int>> ans(people.size());

        vector<int> positions = get_positions(people);

        for (int i = 0; i < people.size(); i++) {
            ans[positions[i]] = people[i];
        }

        return ans;
    }
};
