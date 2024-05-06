class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& sol, vector<vector<int>>& moves) {

        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {// i start from zero
                    queue<pair<int, int>> Q;
                    vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
                    sol[i][j] = 0;
                    Q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    while (!Q.empty()) {
                        pair<int, int> s = Q.front();
                        Q.pop();
                        for (int k = 0; k < moves.size(); k++) {
                            int newRow = s.first + moves[k][0];
                            int newCol = s.second + moves[k][1];
                            if (newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() &&
                                mat[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
                                Q.push(make_pair(newRow, newCol));
                                visited[newRow][newCol] = 1;
                                sol[newRow][newCol] = min(sol[s.first][s.second] + 1, sol[newRow][newCol]);
                            }

                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> solution(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        vector<vector<int>> moves = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        bfs(mat, solution, moves);
        return solution;
    }
};
// the thing with this is that it is not optimised to run bfs from every 0 , 
// so if we append all the zero initially push it to the stack ,  here this way i dont need to check for minimum again and again, as i will do bfs from each 0 so my code changes this way?

void bfs(vector<vector<int>>& mat, vector<vector<int>>& sol, vector<vector<int>>& moves) {
    queue<pair<int, int>> Q;
    vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0)); // Declaration of visited matrix
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 0) {
                Q.push(make_pair(i, j));
                sol[i][j] = 0;
            }
        }
    }
    while (!Q.empty()) {
        pair<int, int> s = Q.front();
        Q.pop();
        for (int k = 0; k < moves.size(); k++) {
            int newRow = s.first + moves[k][0];
            int newCol = s.second + moves[k][1];
            if (newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() &&
                mat[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
                Q.push(make_pair(newRow, newCol));
                visited[newRow][newCol] = 1;
                sol[newRow][newCol] = min(sol[s.first][s.second] + 1, sol[newRow][newCol]);
            }
        }
    }
}
