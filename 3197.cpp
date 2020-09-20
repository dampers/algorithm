#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int r, c;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int gcheck[1501][1501];
vector<string> mp;
queue<pair<int, int>> post, prex;
vector<int> parent(1);

struct fuckswan
{
	int y;
	int x;
};
fuckswan swan[2];

int find(int v);
void merge(int v, int u);
void init();
void swan_init(int y, int x);
void dotbfs(int y, int x, int parent);


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>r>>c;
	mp.resize(r);
	for(int i=0;i<r;i++)
		cin>>mp[i];
	init();
	if(find(gcheck[swan[0].y][swan[0].x])==find(gcheck[swan[1].y][swan[1].x]))
	{
		cout<<0;
		return 0;
	}
	int cnt = 0;
	while(!prex.empty())
	{
		cnt++;
		int size = prex.size();
		while(size--)
		{
			int y = prex.front().first, x = prex.front().second;
			prex.pop();
			mp[y][x] = '.';
			bool flag = false;
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=r||ny<0||nx>=c||nx<0) continue;
				if(mp[ny][nx]=='X' && gcheck[ny][nx]==0)
				{
					gcheck[ny][nx] = -1;
					prex.push({ny, nx});
				}
				if(gcheck[ny][nx]>0)
				{
					if(!flag)
					{
						flag = true;
						gcheck[y][x] = gcheck[ny][nx];
					}
					else merge(gcheck[y][x], gcheck[ny][nx]);
				}
			}
		}
		if(find(gcheck[swan[0].y][swan[0].x])==find(gcheck[swan[1].y][swan[1].x]))
		{
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}

int find(int v)
{
	if(parent[v]==v) return v;
	return parent[v] = find(parent[v]);
}
void merge(int v, int u)
{
	v = find(v);
	u = find(u);
	if(u==v) return;
	if(u>v) swap(u, v);
	parent[u] = v;
}

void dotbfs(int y, int x, int parent)
{
	queue<pair<int, int>> dot;
	dot.push({y, x});
	while(!dot.empty())
	{
		y = dot.front().first, x = dot.front().second;
		dot.pop();
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny>=r||ny<0||nx>=c||nx<0) continue;
			if(gcheck[ny][nx]!=0) continue;
			if(mp[ny][nx]=='.' || mp[ny][nx]=='L')
			{
				gcheck[ny][nx] = parent;
				dot.push({ny, nx});
			}
			else if(mp[ny][nx]=='X'&&gcheck[ny][nx]==0)
			{
				gcheck[ny][nx] = -1;
				prex.push({ny, nx});
			}
		}
	}
}

void init()
{
	swan[0].x = -1;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mp[i][j]=='L') swan_init(i, j);
			if(gcheck[i][j]!=0) continue;
			if(mp[i][j]=='L' || mp[i][j]=='.')
			{
				parent.push_back(parent.size());
				gcheck[i][j] = parent.size()-1;
				dotbfs(i, j, gcheck[i][j]);
			}
			else if(mp[i][j]=='X' && gcheck[i][j]==0)
			{
				for(int d=0;d<4;d++)
				{
					int ny = i+dy[d], nx = j+dx[d];
					if(ny>=r||ny<0||nx>=c||nx<0) continue;
					if(mp[ny][nx]=='.'||mp[ny][nx]=='L')
					{
						gcheck[i][j] = -1;
						prex.push({i, j});
						break;
					}
				}
			}
		}
	}
}

void swan_init(int y, int x)
{
	if(swan[0].x==-1)
	{
		swan[0].x = x;
		swan[0].y = y;
	}
	else
	{
		swan[1].x = x;
		swan[1].y = y;
	}
}