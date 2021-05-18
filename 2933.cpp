#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int dir_cnt = 4;
int r, c;

int dfs(vector<string>& cave, vector<vector<bool>>& check, int y, int x)
{
	check[y][x] = true;
	int ret = y;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny >= r || nx >= c || ny < 0 || nx < 0) continue;
		if(check[ny][nx] || cave[ny][nx] == '.') continue;
		ret = max(ret, dfs(cave, check, ny, nx));
	}
	return ret;
}

void gravity(vector<string>& cave, vector<vector<bool>>& check)
{
	int mn = INT_MAX, y = -1;
	for(int i=0;i<c;i++)
	{
		y = -1;
		for(int j=r-1;j>=0;j--)
		{
			if(check[j][i] == true)
			{
				y = j;
				break;
			}
		}
		if(y == -1) continue;
		int tmp = y;
		while(tmp+1 < r && cave[tmp+1][i] == '.') tmp++;
		mn = min(mn, tmp-y);
	}
	for(int i=r-1;i>=0;i--)
	{
		for(int j=0;j<c;j++)
		{
			if(check[i][j] == true)
			{
				cave[i][j] = '.';
				cave[i+mn][j] = 'x';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	vector<string> cave(r, "");
	for(int i=0;i<r;i++)
		cin >> cave[i];

	int n;
	cin >> n;
	vector<int> stick(n, 0);
	for(int i=0;i<n;i++)
	{
		cin >> stick[i];
		stick[i] = r - stick[i];
	}

	for(int i=0;i<n;i++)
	{
		int y = stick[i], x = -1;
		if(i % 2) // <-
		{
			for(int j=c-1;j>=0;j--)
			{
				if(cave[y][j] == 'x')
				{
					x = j;
					break;
				}
			}
		}
		else // ->
		{
			for(int j=0;j<c;j++)
			{
				if(cave[y][j] == 'x')
				{
					x = j;
					break;
				}
			}
		}
		if(x == -1) continue;
		cave[y][x] = '.';
		for(int d=0;d<dir_cnt;d++)
		{
			int ny = y+dy[d], nx = x+dx[d];
			if(ny >= r || nx >= c || ny < 0 || nx < 0 ) continue;
			if(cave[ny][nx] == '.') continue;
			vector<vector<bool>> check(r, vector<bool>(c, false));
			int bottom = dfs(cave, check, ny, nx);
			if(bottom == r-1) continue;
			gravity(cave, check);
		}
	}
	for(int i=0;i<r;i++)
	{
		cout << cave[i] << endl;
	}
	return 0;
}