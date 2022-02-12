#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int bfs(int eplace, vector<vector<int>> v, vector<pair<int, pii>>& place)
{
	queue<pii> q;
	for(size_t i=0;i<place.size();i++)
	{
		if(place[i].first == 1)
		{
			q.push(place[i].second);
			v[place[i].second.first][place[i].second.second] = 1;
			eplace--;
		}
	}
	if(eplace == 0) return 0;
	int cnt = 0;
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		while(size--)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i];
				int nx = x+dx[i];
				if(ny >= v.size() || nx >= v.size() || ny < 0 || nx < 0) continue;
				if(v[ny][nx] > 0 || v[ny][nx] == -1) continue;
				eplace--;
				if(eplace == 0) return cnt;
				q.push({ny, nx});
				v[ny][nx] = cnt;
			}
		}
	}
	return INT_MAX;
}

int recurr(int pos, int m, int k, int eplace, vector<vector<int>>& v,
	vector<pair<int, pii>>& place)
{
	int ret = INT_MAX;
	if(pos == m)
	{
		ret = min(ret, bfs(eplace, v, place));
		return ret;
	}
	for(size_t i=k;i<place.size();i++)
	{
		if(place[i].first) continue;
		place[i].first = 1;
		ret = min(ret, recurr(pos+1, m, i+1, eplace, v, place));
		place[i].first = 0;
	}
	return ret;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	time_t start = clock();
 
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<pair<int, pii>> place;
	int eplace = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> v[i][j];
			if(v[i][j] == 2)
			{
				place.push_back({0, {i, j}});
			}
			if(v[i][j] == 2 || v[i][j] == 0) eplace++;
			v[i][j] = -v[i][j];
		}
	}
	int ans = recurr(0, m, 0, eplace, v, place);
	cout << (ans==INT_MAX?-1:ans);

	return 0;
}
