#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    bool bfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        
        while (!q.empty()) {
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adj[current]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, current});
                } else if (adjNode != parent) {
                    return true;  // cycle detected
                }
            }
        }
        return false;  
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter edges (u v) (1-based index):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    Solution obj;
    if (obj.isCycle(V, adj)) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
