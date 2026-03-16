#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;

    for(int it : adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it, node, vis, adj))
                return true;
        }
        else if(it != parent)
        {
            return true; // cycle found
        }
    }

    return false;
}

bool detectCycle(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V,0);

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i, -1, vis, adj))
                return true;
        }
    }

    return false;
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
        adj[v].push_back(u);
    }

    if(detectCycle(V,adj))
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle"<<endl;

    return 0;
}