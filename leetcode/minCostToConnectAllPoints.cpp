class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// Here edge is defined by first by weight, then start and end
vector<vector<pair<int, int>>> kruskal(vector<vector<int>>& edges, int size) {
    vector<vector<pair<int, int>>> adlist(size);
    sort(edges.begin(), edges.end());
    DisjointSet ds(size);
    for (int i = 0; i < edges.size(); i++) {
        int weight = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        if (ds.findUPar(u) != ds.findUPar(v)) {
            ds.unionByRank(u, v);
            adlist[u].push_back(make_pair(v, weight));
            adlist[v].push_back(make_pair(u, weight)); // For undirected graph
        }
    }
    return adlist;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Generate edges
        vector<vector<int>> edges;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({weight, i, j});
            }
        }

        // Apply Kruskal's algorithm to find minimum spanning tree
        vector<vector<pair<int, int>>> adlist = kruskal(edges, n);

        // Calculate total weight
        int totalWeight = 0;
        for (auto& list : adlist) {
            for (auto& pair : list) {
                totalWeight += pair.second;
            }
        }
        // Since each edge is counted twice in the adjacency list, divide by 2
        totalWeight /= 2;

        return totalWeight;
    }
};