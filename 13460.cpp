#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0}; // right, left, down, up

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<string> mp(n);
	for(int i=0;i<n;i++)
		cin>>mp[i];
	pair<int ,int> r, b;
	map<pair<pair<int, int>, pair<int, int>>, int> check;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='R')
			{
				r.first = i;
				r.second = j;
				mp[i][j] = '.';
			}
			else if(mp[i][j]=='B')
			{
				b.first = i;
				b.second = j;
				mp[i][j] = '.';
			}
		}
	}
	check[{r, b}] = 1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({r, b});
	int cnt = 0;
	bool flag = false;
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		while(size--)
		{
			pair<int, int> rt, bt;
			rt = q.front().first, bt = q.front().second;
			q.pop();
			// right
			if(rt.second>bt.second) // red first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[rtmp.first][rtmp.second+1]=='.') rtmp.second++;
				if(mp[rtmp.first][rtmp.second+1]=='O') flag = true;
				else mp[rtmp.first][rtmp.second] = 'R';
				while(mp[btmp.first][btmp.second+1]=='.') btmp.second++;
				if(mp[btmp.first][btmp.second+1]=='O') flag = false;
				else if(flag) break;
				else
				{
					mp[rtmp.first][rtmp.second] = '.';
					if(check[{rtmp, btmp}]==0)
					{
						q.push({rtmp, btmp});
						check[{rtmp, btmp}] = 1;
					}
				}
				mp[rtmp.first][rtmp.second] = '.';
			}
			else // blue first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[btmp.first][btmp.second+1]=='.') btmp.second++;
				if(mp[btmp.first][btmp.second+1]!='O')
				{
					mp[btmp.first][btmp.second] = 'B';
					while(mp[rtmp.first][rtmp.second+1]=='.') rtmp.second++;
					if(mp[rtmp.first][rtmp.second+1]=='O')
					{
						flag = true;
						break;
					}
					else
					{
						mp[btmp.first][btmp.second] = '.';
						if(check[{rtmp, btmp}]==0)
						{
							q.push({rtmp, btmp});
							check[{rtmp, btmp}] = 1;
						}
					}
				}
			}
			// left
			if(rt.second<bt.second) // red first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[rtmp.first][rtmp.second-1]=='.') rtmp.second--;
				if(mp[rtmp.first][rtmp.second-1]=='O') flag = true;
				else mp[rtmp.first][rtmp.second] = 'R';
				while(mp[btmp.first][btmp.second-1]=='.') btmp.second--;
				if(mp[btmp.first][btmp.second-1]=='O') flag = false;
				else if(flag) break;
				else
				{
					mp[rtmp.first][rtmp.second] = '.';
					if(check[{rtmp, btmp}]==0)
					{
						q.push({rtmp, btmp});
						check[{rtmp, btmp}] = 1;
					}
				}
				mp[rtmp.first][rtmp.second] = '.';
			}
			else // blue first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[btmp.first][btmp.second-1]=='.') btmp.second--;
				if(mp[btmp.first][btmp.second-1]!='O')
				{
					mp[btmp.first][btmp.second] = 'B';
					while(mp[rtmp.first][rtmp.second-1]=='.') rtmp.second--;
					if(mp[rtmp.first][rtmp.second-1]=='O')
					{
						flag = true;
						break;
					}
					else
					{
						mp[btmp.first][btmp.second] = '.';
						if(check[{rtmp, btmp}]==0)
						{
							q.push({rtmp, btmp});
							check[{rtmp, btmp}] = 1;
						}
					}
				}
			}
			// down
			if(rt.first>bt.first) // red first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[rtmp.first+1][rtmp.second]=='.') rtmp.first++;
				if(mp[rtmp.first+1][rtmp.second]=='O') flag = true;
				else mp[rtmp.first][rtmp.second] = 'R';
				while(mp[btmp.first+1][btmp.second]=='.') btmp.first++;
				if(mp[btmp.first+1][btmp.second]=='O') flag = false;
				else if(flag) break;
				else
				{
					mp[rtmp.first][rtmp.second] = '.';
					if(check[{rtmp, btmp}]==0)
					{
						q.push({rtmp, btmp});
						check[{rtmp, btmp}] = 1;
					}
				}
				mp[rtmp.first][rtmp.second] = '.';
			}
			else // blue first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[btmp.first+1][btmp.second]=='.') btmp.first++;
				if(mp[btmp.first+1][btmp.second]!='O')
				{
					mp[btmp.first][btmp.second] = 'B';
					while(mp[rtmp.first+1][rtmp.second]=='.') rtmp.first++;
					if(mp[rtmp.first+1][rtmp.second]=='O')
					{
						flag = true;
						break;
					}
					else
					{
						mp[btmp.first][btmp.second] = '.';
						if(check[{rtmp, btmp}]==0)
						{
							q.push({rtmp, btmp});
							check[{rtmp, btmp}] = 1;
						}
					}
				}
			}
			// up
			if(rt.first<bt.first) // red first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[rtmp.first-1][rtmp.second]=='.') rtmp.first--;
				if(mp[rtmp.first-1][rtmp.second]=='O') flag = true;
				else mp[rtmp.first][rtmp.second] = 'R';
				while(mp[btmp.first-1][btmp.second]=='.') btmp.first--;
				if(mp[btmp.first-1][btmp.second]=='O') flag = false;
				else if(flag) break;
				else
				{
					mp[rtmp.first][rtmp.second] = '.';
					if(check[{rtmp, btmp}]==0)
					{
						q.push({rtmp, btmp});
						check[{rtmp, btmp}] = 1;
					}
				}
				mp[rtmp.first][rtmp.second] = '.';
			}
			else // blue first
			{
				pair<int, int> rtmp = {rt.first, rt.second}, btmp = {bt.first, bt.second};
				while(mp[btmp.first-1][btmp.second]=='.') btmp.first--;
				if(mp[btmp.first-1][btmp.second]!='O')
				{
					mp[btmp.first][btmp.second] = 'B';
					while(mp[rtmp.first-1][rtmp.second]=='.') rtmp.first--;
					if(mp[rtmp.first-1][rtmp.second]=='O')
					{
						flag = true;
						break;
					}
					else
					{
						mp[btmp.first][btmp.second] = '.';
						if(check[{rtmp, btmp}]==0)
						{
							q.push({rtmp, btmp});
							check[{rtmp, btmp}] = 1;
						}
					}
				}
			}
		}
		if(flag) break;
	}
	if(flag && cnt<11) cout<<cnt;
	else cout<<-1;
	return 0;
}