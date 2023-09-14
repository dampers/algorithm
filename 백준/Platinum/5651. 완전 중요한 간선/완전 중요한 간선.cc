#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, M;
int capacity[303][303];
int flows[303][303];

inline bool is_possible(int curr, int next)
{
    return capacity[curr][next] - flows[curr][next] > 0;
}

vector<int> find_path(vector<vector<int>>& adj, int source, int sink)
{
    vector<int> prev(N+1, -1);
    queue<int> q;
    q.push(source);

    while(!q.empty() && prev[sink] == -1)
    {
        int curr = q.front();
        q.pop();

        for(int next : adj[curr])
        {
            if(is_possible(curr, next) && prev[next] == -1)
            {
                prev[next] = curr;
                q.push(next);
                if(next == sink) break;
            }
        }
    }
    return prev;
}

int network_flow(vector<vector<int>>& adj, int source, int sink)
{
    int total = 0;
    vector<int> prev;
    while(1)
    {
        prev = find_path(adj, source, sink);
        if(prev[sink] == -1) break;
        int flow = INT_MAX;
        for(int i=sink;i!=source;i=prev[i])
            flow = min(flow, capacity[prev[i]][i] - flows[prev[i]][i]);
        
        for(int i=sink;i!=source;i=prev[i])
        {
            flows[prev[i]][i] += flow;
            flows[i][prev[i]] -= flow;
        }
        total += flow;
    }
    return total;
}

void solve()
{
    
    cin >> N >> M;
    vector<vector<int>> adj(N+1, vector<int>());
    memset(capacity, 0, sizeof(capacity));
    memset(flows, 0, sizeof(flows));

    int f, t, b;
    vector<pii> cedges;
    for(int i=0;i<M;i++)
    {
        cin >> f >> t >> b;
        adj[f].push_back(t);
        adj[t].push_back(f);
        capacity[f][t] += b;
        cedges.push_back({f, t});
    }

    int source = 1, sink = N;
    int total = network_flow(adj, source, sink);

    vector<pii> full_edge;
    for(pii E : cedges)
    {
        int Sedge = E.first, Eedge = E.second;
        if(capacity[Sedge][Eedge] - flows[Sedge][Eedge] == 0) full_edge.push_back({Sedge, Eedge});
    }

    int ans = 0;
    for(pii K : full_edge)
    {
        int psource = K.first, psink = K.second;
        vector<int> par = find_path(adj, psource, psink);
        if(par[psink] == -1) ans++;
    }

    cout << ans << endl;

}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    while(K--)
    {
        solve();
    }

    return 0;
}