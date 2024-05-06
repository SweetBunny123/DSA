class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        int totalCost = 0;

        // Start from the first point
        minDist[0] = 0;

        // Priority queue to store vertices ordered by their minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Add the first point to the priority queue
        pq.push({0, 0}); // {distance, vertex}

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            // Skip if already visited
            if (visited[u]) continue;

            // Mark the current vertex as visited
            visited[u] = true;

            // Add the distance to the total cost
            totalCost += dist;

            // Update minimum distances of adjacent vertices
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int newDist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (newDist < minDist[v]) {
                        minDist[v] = newDist;
                        pq.push({minDist[v], v});
                    }
                }
            }
        }

        return totalCost;
    }
};