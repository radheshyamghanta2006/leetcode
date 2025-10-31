class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Code with Radheshyam (.^.)
         // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int shortest = INT_MAX;
        // Step 2: BFS from every vertex
        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        // First time visiting this node
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } 
                    else if (dist[v] >= dist[u]) {
                        // Already visited and not parent => cycle found
                        shortest = min(shortest, dist[v] + dist[u] + 1);
                    }
                }
            }
        }

        return (shortest == INT_MAX) ? -1 : shortest;
        
    }
};