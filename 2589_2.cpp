#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char trs[55][55];
bool check[55][55];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
	int l, w;
	scanf("%d %d", &l, &w);
	for(int i=0;i<l;i++)
		scanf(" %s", trs[i]);
	queue<pair<int, int>> q;
	int cnt = 0;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<w;j++)
		{
			int kcnt = -1;
			memset(check, false, sizeof(check));
			if(trs[i][j]=='L')
			{
				q.push(make_pair(i, j));
				while(!q.empty())
				{
					int size = q.size();
					kcnt++;
					for(int k=0;k<size;k++)
					{
						int y = q.front().first, x = q.front().second;
						q.pop();
						for(int dir=0;dir<4;dir++)
						{
							int ny = y+dy[dir], nx = x+dx[dir];
							if(ny>=l||nx>=w||ny<0||nx<0) continue;
							else if(trs[ny][nx]=='W'||check[ny][nx]==true) continue;
							check[ny][nx] = true;
							q.push(make_pair(ny, nx));
						}
					}
				}
			}
			cnt = max(kcnt, cnt);
		}
	}
	cout<<cnt;
	return 0;
}