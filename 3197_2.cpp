#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int mp[1505][1505];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int parent[1200000], r, c;
int ay, ax, ap, by, bx, bp, cnt;

int find(int u)
{
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(u<v) swap(u, v);
	parent[v] = u;
}

void dfs(int y, int x, int p)
{
	if(y==ay && x==ax) ap = p;
	else if(y==by && x==bx) bp = p;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=r || nx>=c || ny<0 || nx<0) continue;
		if(mp[ny][nx]==0 || mp[ny][nx]>0) continue;
		mp[ny][nx] = p;
		dfs(ny, nx, p);
	}
}

int main()
{
	scanf("%d %d", &r, &c);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			char tmp;
			scanf(" %c", &tmp);
			if(tmp!='X') mp[i][j] = -1;
			if(cnt==0 && tmp=='L')
			{
				cnt++;
				ay = i;
				ax = j;
			}
			else if(cnt==1 && tmp=='L')
			{
				by = i;
				bx = j;
			}
		}
	}
	cnt = 1;
	queue<pair<int, pair<int, int>>> q;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mp[i][j]==-1)
			{
				parent[cnt] = cnt;
				dfs(i, j, cnt);
				cnt++;
			}
			if(mp[i][j]!=0)
			{
				for(int k=0;k<4;k++)
				{
					int ny = i+dy[k], nx = j+dx[k];
					if(ny>=r || nx>=c || ny<0 || nx<0) continue;
					if(mp[ny][nx]==0)
					{
						q.push({mp[i][j], {i, j}});
						break;
					}
				}
			}
		}
	}
	int day = 0;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int y = q.front().second.first, x = q.front().second.second;
			int num = q.front().first;
			num = find(num);
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=r || nx>=c || ny<0 || nx<0) continue;
				if(mp[ny][nx]!=0)
				{
					merge(num, mp[ny][nx]);
					if(find(ap)==find(bp))
					{
						printf("%d", day);
						return 0;
					}
				}
			}
			q.push({num, {y, x}});
		}
		day++;
		size = q.size();
		while(size--)
		{
			int y = q.front().second.first, x = q.front().second.second;
			int num = q.front().first;
			num = find(num);
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=r || nx>=c || ny<0 || nx<0) continue;
				if(mp[ny][nx]==0)
				{
					mp[ny][nx] = num;
				}
				else
				{
					merge(num, mp[ny][nx]);
					if(find(ap)==find(bp))
					{
						printf("%d", day);
						return 0;
					}
					num = find(num);
				}
				q.push({num, {ny, nx}});
			}
		}
	}

	return 0;
}