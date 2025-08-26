#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool visited[105];
int parent[105];
bool cycle;


void dfs(int src)
{
    visited[src] = true;

    for(auto child : adj_list[src])
    {
        if(visited[child] && parent[src] != child)
            cycle = true;
        

        if(!visited[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    cycle = false;
    dfs(0);

    for(int i = 0; i < n; i++)
    {
        cout << i << " parent: " << parent[i] << endl;
    }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;


    
    return 0;
}
