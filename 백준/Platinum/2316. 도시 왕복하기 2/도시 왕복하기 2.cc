#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


int N, P;
const int MAXV = 808;
vector<int> adj[MAXV];
int capacity[MAXV][MAXV];
int flows[MAXV][MAXV];

inline int get_inof(int u)
{
    return u << 1;
}

inline int get_outof(int u)
{
    return (u << 1) + 1;
}

bool is_possible(int curr, int next)
{
    return capacity[curr][next] - flows[curr][next] > 0;
}


vector<int> find_path(int start, int end)
{
    vector<int> prev(MAXV, -1);
    queue<int> q;
    q.push(start);

    while(!q.empty() && prev[end] == -1)
    {
        int curr = q.front();
        q.pop();
        
        for(int next : adj[curr])
        {
            if(is_possible(curr, next) && prev[next] == -1)
            {
                prev[next] = curr;
                q.push(next);
                if(next == end) break;
            }
        }
    }
    return prev;
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P;
    
    int u, v;
    for(int i=3;i<=N;i++)
    {
        int oti = get_outof(i), ini = get_inof(i);
        adj[ini].push_back(oti);
        adj[oti].push_back(ini);
        capacity[ini][oti] = 1;
    }

    for(int i=0;i<P;i++)
    {
        cin >> u >> v;
        int otu = get_outof(u), inu = get_inof(u);
        int otv = get_outof(v), inv = get_inof(v);
        adj[otu].push_back(inv);
        adj[inv].push_back(otu);
        adj[otv].push_back(inu);
        adj[inu].push_back(otv);
        capacity[otu][inv] = 1;
        capacity[otv][inu] = 1;
    }

    int res = 0, start = get_outof(1), end = get_inof(2);
    while(1)
    {
        vector<int> prev = find_path(start, end);
        if(prev[end] == -1) break;

        int flow = INT_MAX;
        for(int i=end;i!=start;i=prev[i])
        {
            flow = min(flow, capacity[prev[i]][i] - flows[prev[i]][i]);
        }
        for(int i=end;i!=start;i=prev[i])
        {
            flows[prev[i]][i] += flow;
            flows[i][prev[i]] -= flow;
        }
        res += flow;
    }
    cout << res;

    return 0;
}