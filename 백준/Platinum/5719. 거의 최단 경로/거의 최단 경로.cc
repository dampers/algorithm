#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, s, d;

void erase(vvi& prev, vvi& adj, int curr)
{
    for(int x : prev[curr])
    {
        for(int i=0;i<n;i++)
        {
            if(adj[x][curr])
            {
                adj[x][curr] = 0;
                erase(prev, adj, x);
            }
        }
    }
}

int dijkstra(vvi& adj)
{
    vi cost(n, INT_MAX);
    vvi prev(n+1, vector<int>());
    cost[s] = 0;
    
    // cost, curr
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        int ccost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(cost[curr] < ccost) continue;
        for(int next=0;next<n;next++)
        {
            if(adj[curr][next])
            {
                if(cost[next] == ccost + adj[curr][next])
                {
                    prev[next].emplace_back(curr);
                }
                else if(cost[next] > ccost + adj[curr][next])
                {
                    prev[next].clear();
                    prev[next].emplace_back(curr);
                    cost[next] = ccost + adj[curr][next];
                    pq.push({cost[next], next});
                }
            }
        }
    }

    erase(prev, adj, d);
    

    return cost[d];
}

void solve()
{
    vvi adj(n, vector<int>(n, 0));
    cin >> s >> d;
    int u, v, p;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> p;
        adj[u][v] = p;
    }

    dijkstra(adj);
    int ncost = dijkstra(adj);
    if(ncost == INT_MAX) cout << -1 << endl;
    else cout << ncost << endl;
    

}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve();
    }

    return 0;
}