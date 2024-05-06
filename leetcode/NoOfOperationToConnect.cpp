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

    void unionByRank(int u, int v) {//here rank means height;
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;//if parent is same 
        if (rank[ulp_u] < rank[ulp_v]) {

            parent[ulp_u] = ulp_v; //
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+= size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
    }
};


int bfs(vector<vector<int>>& adlist, vector<int>& c) {
    queue<int> Q;
    int count = 0; 
    for(int i = 0; i < adlist.size(); i++) {
        if(c[i] == 0) {   
            Q.push(i);
            count++;
            c[i] = count;
            while (!Q.empty()) {
                int s = Q.front();
                Q.pop();
                vector<int> u = adlist[s];
                for (int j = 1; j < u.size(); j++) {
                    int v = u[j];
                    if (c[v] == 0) {
                        Q.push(v);
                        c[v] = count;
                    }
                }
            }
        }
    }
    return count;
}

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        vector<vector<int>>adlist(n);
        for(int i =0 ; i< adlist.size(); i++)
        {
            adlist[i].push_back(i);
        }
        int to_remove= 0;
        for(int i =0 ;i< connections.size(); i++)
        {
            int u = connections[i][0];
            int v= connections[i][1];
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                adlist[u].push_back(v);
                adlist[v].push_back(u);
                ds.unionByRank(u, v);
            }
            else
            {
                to_remove++;
            }   
        }
        vector<int>visit(n, 0);
        int unique  = bfs(adlist, visit);
        cout<<unique<<" "<<to_remove<<endl;
        if(unique-1<= to_remove)return unique-1;
        else return -1;
    }
};