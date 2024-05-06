class Solution {
public:

    int bfs(vector<vector<int>>& adlist, int src, vector<int>& v, vector<int>& restricted) {
        queue<int> Q;
        int count = 0; 
        Q.push(src);
        v[src] = 1;
        while (!Q.empty()) {
            vector<int> u = adlist[Q.front()];
            Q.pop();
            count++;
            cout << u[0] << endl;
            if (u.size() > 1) {
                for (int i = 1; i < u.size(); i++) {
                    if (v[u[i]] != 1 && restricted[u[i]] != 1) {
                        Q.push(u[i]);
                        v[u[i]] = 1;
                    }
                }
            }
        }
        return count;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adlist(n);
        vector<int> res(n, 0); // Corrected initialization
        for (int i = 0; i < restricted.size(); i++) {
            res[restricted[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            adlist[i].push_back(i);
        }
        for (int i = 0; i < edges.size(); i++) {
            adlist[edges[i][0]].push_back(edges[i][1]);
            adlist[edges[i][1]].push_back(edges[i][0]); 
        }
        vector<int> v(n, 0);
        int count = bfs(adlist, 0, v, res);
        return count;
    }
};
