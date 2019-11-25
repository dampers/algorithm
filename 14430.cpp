#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int wook[303][303];
int dx[] = {0, 1};
int dy[] = {1, 0};
int check[303][303];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>wook[i][j];
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 0}, wook[0][0]});
	check[0][0] = wook[0][0];
	int mx = wook[0][0];
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int y = q.front().first.first, x = q.front().first.second, cnt = q.front().second;
			q.pop();
			for(int i=0;i<2;i++)
			{
				int ny = y+dy[i], nx = x+dx[i], ncnt = cnt;
				if(ny>=n || nx>=m ||check[ny][nx]>ncnt) continue;
				if(wook[ny][nx]==1) ncnt++;
				q.push({{ny, nx}, ncnt});
				mx = max(mx, ncnt);
				check[ny][nx] = max(check[ny][nx], ncnt);
			}
		}
	}
	cout<<mx;
	return 0;
}