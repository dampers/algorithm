#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, ans;
int esize;
int bfs(vector<pii>& virus, vector<vector<int>> v, vector<bool>& check)
{
	queue<pii> q;
	for(size_t i=0;i<check.size();i++)
	{
		if(check[i])
		{
			q.push(virus[i]);
			v[virus[i].first][virus[i].second] = 0;
		}
		else v[virus[i].first][virus[i].second] = -3;
	}
	int ret = 0;
	int fsize = check.size();
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
				if(v[ny][nx] == -1) continue;
				if(v[ny][nx] == -2)
				{
					v[ny][nx] = v[y][x]+1;
					q.push({ny, nx});
					ret = max(ret, v[ny][nx]);
					fsize++;
				}
				else if(v[ny][nx] == -3)
				{
					v[ny][nx] = v[y][x]+1;
					q.push({ny, nx});
				}
			}
			if(fsize == esize) break;
		}
		if(fsize == esize) break;
	}
	if(fsize == esize) return ret;
	return INT_MAX;
}

void recurr(int pos, vector<pii>& virus, vector<vector<int>>& v, vector<bool>& check, int k)
{
	if(pos == m)
	{
		ans = min(ans, bfs(virus, v, check));
		return;
	}
	for(size_t i=k;i<virus.size();i++)
	{
		if(check[i]) continue;
		check[i] = true;
		recurr(pos+1, virus, v, check, i+1);
		check[i] = false;
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<pii> virus;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> v[i][j];
			if(v[i][j] == 2)
			{
				virus.push_back({i, j});
				v[i][j] = -2;
				esize++;
			}
			else if(v[i][j] == 1)
				v[i][j] = -1;
			else if(v[i][j] == 0)
			{
				esize++;
				v[i][j] = -2;
			}
		}
	}
	vector<bool> check(virus.size(), false);
	ans = INT_MAX;
	recurr(0, virus, v, check, 0);
	if(ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}