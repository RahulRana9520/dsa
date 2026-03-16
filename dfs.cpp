#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &result)
{
    vis[node] = 1;          // mark node visited
    result.push_back(node); // store node in DFS result

    for(int it : adj[node]) // visit all neighbours
    {
        if(!vis[it])
        {
            dfs(it, vis, adj, result);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V,0);
    vector<int> result;

    dfs(0, vis, adj, result); // start DFS from node 0

    return result;
}

int main()
{
    int V,E;

    cout<<"Enter number of vertices: ";
    cin>>V;

    cout<<"Enter number of edges: ";
    cin>>E;

    vector<vector<int>> adj(V);

    cout<<"Enter edges (u v):"<<endl;

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<int> dfsResult = dfsOfGraph(V, adj);

    cout<<"DFS Traversal: ";

    for(int node : dfsResult)
        cout<<node<<" ";

    cout<<endl;

    return 0;
}