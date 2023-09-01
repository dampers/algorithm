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

int N;
stack<int> adj[1111];
int edges[1111][1111];
int degree[1111];

void find_Euler(int curr)
{
    while(!adj[curr].empty())
    {
        int next = adj[curr].top();
        adj[curr].pop();
        if(edges[curr][next] && edges[next][curr])
        {
            edges[curr][next]--;
            edges[next][curr]--;
            find_Euler(next);
        }
    }
    cout << curr << ' ';
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int tmp;
            cin >> tmp;
            while(tmp--)
            {
                adj[i].push(j);
                edges[i][j]++;
                degree[j]++;
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        if(degree[i] % 2)
        {
            cout << -1;
            return 0;
        }
    }

    find_Euler(1);

    return 0;
}