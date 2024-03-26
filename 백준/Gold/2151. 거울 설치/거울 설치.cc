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

int mirror[4][55][55];

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> vs(N, "");
    for(int i=0;i<N;i++)
        cin >> vs[i];

    // {mirror cont, dir}, {y, x}
    pair<pii, pii> start = {{0, -1}, {-1, -1}}, end = {{0, -1}, {-1, -1}};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(vs[i][j] == '#')
            {
                if(start.second.second == -1)
                {
                    start.second.first = i;
                    start.second.second = j;
                }
                else
                {
                    end.second.first = i;
                    end.second.second = j;
                }
            }
        }
    }
    memset(mirror, -1, sizeof(mirror));
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
    pq.push({{0, 0}, start.second});
    pq.push({{0, 1}, start.second});
    pq.push({{0, 2}, start.second});
    pq.push({{0, 3}, start.second});
    // mirror[start.first.second][start.second.first][start.second.second] = 0;
    // cout << "goal : " << end.second.first << ' ' << end.second.second << endl;
    
    int ans = INT_MAX;
    while(!pq.empty())
    {
        int mcnt = pq.top().first.first;
        int dir = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();


        // cout << y << ' ' << x << ' ' << dir  << endl;
        // cout << mirror[dir][y][x] << ' ' << mcnt << endl;
        if(mirror[dir][y][x] >= 0 && mirror[dir][y][x] < mcnt) continue;
        if(y == end.second.first && x == end.second.second && ans > mcnt)
        {
            ans = mcnt;
            continue;
        }
        
        int ny = y+dy[dir];
        int nx = x+dx[dir];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N || vs[ny][nx] == '*') continue;
        if( (vs[ny][nx] == '.' || vs[ny][nx] == '#') && (mirror[dir][ny][nx] == -1 || mcnt < mirror[dir][ny][nx]))
        {
            mirror[dir][ny][nx] = mcnt;
            pq.push({{mcnt, dir}, {ny, nx}});
        }
        if(vs[ny][nx] == '!' )
        {
            for(int ndir=0; ndir<4; ndir++)
            {
                if(ndir % 2 == 0 && ndir+1 == dir) continue;
                if(ndir % 2 && ndir-1 == dir) continue;
                if(ndir != dir && (mirror[ndir][ny][nx] == -1 || mcnt+1 < mirror[ndir][ny][nx]))
                {
                    mirror[ndir][ny][nx] = mcnt+1;
                    pq.push({{mcnt+1, ndir}, {ny, nx}});
                }

                else if(ndir == dir && (mirror[ndir][ny][nx] == -1 || mcnt < mirror[ndir][ny][nx]))
                {
                    mirror[ndir][ny][nx] = mcnt;
                    pq.push({{mcnt, ndir}, {ny, nx}});
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}