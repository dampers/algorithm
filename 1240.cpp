#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int bfs(vector<vector<pii>>& v, int a, int b)
{
    queue<pii> q;
    vector<bool> check(v.size(), false);
    check[a] = true;
    q.push({a, 0});
    while(!q.empty())
    {
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int i=0;i<v[curr].size();i++)
        {
            int next = v[curr][i].first;
            int ncost = v[curr][i].second;
            if(check[next]) continue;
            if(next == b) return cost+ncost;
            check[next] = true;
            q.push({next, cost+ncost});
        }
    }
    return INT_MAX;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> v(n+1, vector<pii>());
    int a, b, d;
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    while(m--)
    {
        cin >> a >> b;
        cout << bfs(v, a, b) << endl;
    }

	return 0;
}
