#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

string ice[1505];
int dismap[1505][1505];
int r, c;
int parent[2500001];

void input(pair<int, int>& l1, pair<int, int>& l2)
{
	for(int i=0;i<r;i++)
	{
		cin >> ice[i];
		for(int j=0;j<c;j++)
		{
			if(ice[i][j] == 'L')
			{
				if(l1.first == -1)
				{
					l1.first = i;
					l1.second = j;
				}
				else
				{
					l2.first = i;
					l2.second = j;
				}
			}
		}
	}
}

void dfs(int y, int x, int discnt, queue<pair<int, int>>& q)
{
	dismap[y][x] = discnt;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(dismap[ny][nx]) continue;
		if(ice[ny][nx] == 'X')
		{
			q.push({ny, nx});
			continue;
		}
		dfs(ny, nx, discnt, q);
	}
}

int find(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]); 
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u == v) return;
	parent[u] = v;
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	pair<int, int> l1 = {-1, -1}, l2 = {-1, -1};

	input(l1, l2);
	
	queue<pair<int, int>> q;
	int discnt = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if((ice[i][j] == '.' || ice[i][j] == 'L') && dismap[i][j] == 0)
			{
				discnt++;
				parent[discnt] = discnt;
				dfs(i, j, discnt, q);
			}
		}
	}

	int day = 0;
	queue<int> disq;

	while(!q.empty())
	{
		if(find(dismap[l1.first][l1.second]) == find(dismap[l2.first][l2.second]))
		{
			cout << day;
			return 0;
		}
		day++;
		size_t size = q.size();
		while(size--)
		{
			int y = q.front().first, x = q.front().second;
			ice[y][x] = '.';
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
				if(ice[ny][nx] == 'X')
				{
					ice[ny][nx] = '.';
					q.push({ny, nx});
				}
				else if(dismap[ny][nx])
				{
					disq.push(find(dismap[ny][nx]));
				}
			}
			int base = 0;
			while(!disq.empty())
			{
				int tmp = disq.front();
				disq.pop();
				if(base == 0)
				{
					base = tmp;
					continue;
				}
				merge(base, tmp);
			}
			dismap[y][x] = base;
		}
	}

	cout << day;

	return 0;
}