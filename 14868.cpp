#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[100005];
int kcnt[100005];
int mp[2002][2002];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int find(int u)
{
	if(parent[u]==u) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(u<v) swap(u, v);
	parent[v] = u;
	kcnt[u] += kcnt[v];
	kcnt[v] = kcnt[u];
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	queue<pair<int, pair<int, int>>> q;
	int cnt = 1;
	for(int i=0;i<k;i++)
	{
		int y, x;
		cin>>x>>y;
		parent[cnt] = cnt;
		q.push({cnt, {y, x}});
		kcnt[cnt] = 1;
		mp[y][x] = cnt++;
	}
	int year = 0;
	while(!q.empty())
	{
		int size = q.size();
		for(int qsize=0;qsize<size;qsize++)
		{
			int sy = q.front().second.first, sx = q.front().second.second;
			int num = q.front().first;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = sy+dy[i], nx = sx+dx[i];
				num = find(num);
				if(ny>n || nx>n || ny<=0 || nx<=0) continue;
				if(find(mp[ny][nx])==num || mp[ny][nx]==0) continue;
				else
				{
					merge(num, find(mp[ny][nx]));
					if(kcnt[find(num)]==cnt-1)
					{
						cout<<year;
						return 0;
					}
				}
			}
			q.push({num, {sy, sx}});
		}
		year++;
		for(int qsize=0;qsize<size;qsize++)
		{
			int sy = q.front().second.first, sx = q.front().second.second;
			int num = q.front().first;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = sy+dy[i], nx = sx+dx[i];
				num = find(num);
				if(ny>n || nx>n || ny<=0 || nx<=0) continue;
				if(find(mp[ny][nx])==num) continue;
				if(mp[ny][nx]==0) mp[ny][nx] = num;
				else
				{
					merge(num, find(mp[ny][nx]));
					if(kcnt[find(num)]==cnt-1)
					{
						cout<<year;
						return 0;
					}
				}
				q.push({num, {ny, nx}});
			}
		}
	}
	return 0;
}