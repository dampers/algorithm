#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class DisjointSet
{
public:
	vector<int> parent;
	DisjointSet();
	DisjointSet(int size)
	{
		parent.resize(size+1, 0);
		for(int i=0;i<=size;i++)
			parent[i] = i;
	}
	int find(int v)
	{
		if(parent[v] == v) return v;
		return parent[v] = find(parent[v]);
	}
	bool merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u == v) return true;
		if(u > v) parent[u] = v;
		else parent[v] = u;
		return false;
	}
};

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string tmp;
	vector<vector<int>> smp(n, vector<int>(m, 0));
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		for(int j=0;j<m;j++)
		{
			if(tmp[j] == 'R') smp[i][j] = 0;
			else if(tmp[j] == 'L') smp[i][j] = 1;
			else if(tmp[j] == 'D') smp[i][j] = 2;
			else if(tmp[j] == 'U') smp[i][j] = 3;
		}
	}
	vector<vector<bool>> check(n, vector<bool>(m, false));
	DisjointSet DS(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j] == false)
			{
				int y = i, x = j;
				while(1)
				{
					check[y][x] = true;
					int dir = smp[y][x];
					int ny = y+dy[dir], nx = x+dx[dir];
					//if(ny >= n || nx >= m || ny < 0 || nx < 0) break;
					if(DS.merge(y*m+x, ny*m+nx) || check[ny][nx]) break;
					y = ny;
					x = nx;
				}
			}
		}
	}
	int ans = -1;
	for(int i=0;i<DS.parent.size();i++)
	{
		if(DS.find(DS.parent[i]) == i) ans++;
	}
	cout << ans;

    return 0;
}
