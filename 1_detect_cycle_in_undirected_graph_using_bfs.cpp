#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool visited[105];
int parent[105];
bool cycle;


void bfs(int src)
{
    queue<int> q; 
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << endl;

        for(int child : adj_list[par])
        {
            if(visited[child] && parent[par] != child)
            {
                cycle = true;
            }
            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
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

    cycle = false;
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            bfs(i);
    }

    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
