#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char paper[11][11];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, -1, 0, 1, -1, 0};
int main()
{
	int t;
	int nx, ny;
	scanf(" %d", &t);
	for(int q=0;q<t;q++)
	{
		int mx = 0, cnt = 0;
		int n;
		scanf(" %d", &n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf(" %c", &paper[i][j]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(paper[i][j]=='W')
				{
					cnt = 0;
					for(int k=0;k<8;k++)
					{
						ny = i+dy[k];
						nx = j+dx[k];
						if(ny>=0 && nx>=0 && ny<n && nx<n && paper[ny][nx]=='W')
							cnt++;
					}
					if(cnt==0)
						cnt++;
					if(cnt>mx)
						mx = cnt;
				}
			}
		}
		printf("#%d %d\n", q+1, mx);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				paper[i][j] = '\0';
	}
	return 0;
}