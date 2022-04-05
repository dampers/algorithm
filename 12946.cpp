#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {0, 1, -1, 1, -1, 0};
const int dy[] = {-1, -1, 0, 0, 1, 1};

int n;
int mx;
int mxcolor;

void dfs(int y, int x, vector<string>& v, vector<vector<int>>& check)
{
    if(check[y][x]) return;
    for(int c=1;c<=3;c++)
    {
        bool flag = true;
        for(int i=0;i<6;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(ny >= n || nx >= n || ny < 0 || nx < 0 || v[ny][nx] == '-' || check[ny][nx] == 0) continue;
            if(check[ny][nx] == c)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            //cout << y << ' ' << x << ' ' << c << endl;
            check[y][x] = c;
            mx = max(mx, c);
            break;
        }
    }
    if(check[y][x] == 0) return;
    for(int i=0;i<6;i++)
    {
        int ny = y+dy[i], nx = x+dx[i];
        if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
        if(v[ny][nx] == 'X' && check[ny][nx] == 0) dfs(ny, nx, v, check);
    }
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    mxcolor = n*n+5;
    mx = 0;
    
    vector<vector<int>> check(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j] == 'X' && check[i][j] == 0)
            {
                dfs(i, j, v, check);
            }
        }
    }
    cout << mx;

	return 0;
}