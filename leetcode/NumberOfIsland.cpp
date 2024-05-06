#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        // Define directions: up, down, left, right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // Marking as visited

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0'; // Marking as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};
