#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


void floyd(vector<vector<int>>& adj, int N)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                adj[j][k] = min(adj[j][k], adj[j][i]+adj[i][k]);
            }
        }
    }
}

void solve()
{
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> adj(N+1, vector<int>(N+1, INT_MAX));
    for(int i=1;i<=N;i++) adj[i][i] = 0;
    int a, b, c;
    for(int i=0;i<M;i++)
    {
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    cin >> K;
    vector<int> kv(K, 0);
    for(int i=0;i<K;i++)
    {
        cin >> kv[i];
    }
    floyd(adj, N);
    int ans = 1;
    int mncost = INT_MAX;
    for(int i=1;i<=N;i++)
    {
        int tmp = 0;
        for(int j=0;j<K;j++)
            tmp += adj[kv[j]][i];
        if(tmp < mncost)
        {
            mncost = tmp;
            ans = i;
        }
    }
    // cout << mncost << endl;
    cout << ans << endl;
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();

    return 0;
}