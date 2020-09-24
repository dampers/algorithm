#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int h, w;
bool check[22][22];
const int dy[4][2] = {{0, 1}, {1, 1}, {0, 1}, {1, 1}};
const int dx[4][2] = {{1, 1}, {0, 1}, {1, 0}, {-1, 0}};

lld bt(int k, int rest, vector<pair<int, int>>& v)
{
	if(rest==0) return 1LL;
	else if(k>=v.size()) return 0LL;
	int y = v[k].first, x = v[k].second;
	if(check[y][x]) return bt(k+1, rest, v);
	lld res = 0LL;
	check[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int y1 = y+dy[i][0], y2 = y+dy[i][1];
		int x1 = x+dx[i][0], x2 = x+dx[i][1];
		if(y1>=h||y2>=h||x1>=w||x2>=w) continue;
		else if(y1<0||y2<0||x1<0||x2<0) continue;
		else if(check[y1][x1]||check[y2][x2]) continue;
		check[y1][x1] = check[y2][x2] = true;
		res += bt(k+1, rest-3, v);
		check[y1][x1] = check[y2][x2] = false;
	}
	check[y][x] = false;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>h>>w;
		vector<string> mp(h);
		memset(check, false, sizeof(check));
		vector<pair<int, int>> v;
		for(int i=0;i<h;i++)
			cin>>mp[i];
		int rest = 0;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(mp[i][j]=='#') check[i][j] = true;
				else
				{
					v.push_back({i, j});
					rest++;
				}
			}
		}
		if(rest%3)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<bt(0, rest, v)<<endl;
	}
	return 0;
}