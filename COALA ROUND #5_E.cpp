#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char t[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	char a;
	scanf("%d %d %c", &n, &m, &a);
	for(int i=0;i<n;i++)
		scanf(" %s", t[i]);
	vector<char> v;
	int x, y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(t[i][j]==a)
			{
				y = i;
				x = j;
				//printf("x = %d y = %d\n", x, y);
				for(int k=0;k<4;k++)
				{
					bool flag = false;
					int nx = x+dx[k];
					int ny = y+dy[k];
					//printf("%d %d\n", ny, nx);
					if(nx<0 || nx>=m || ny<0 || ny>=n || t[ny][nx]=='.') continue;
					//printf("%d %d %c\n", ny, nx, t[ny][nx]);
					if(t[ny][nx]!=a)
					{
						//printf("%d %d %c\n", ny, nx, t[ny][nx]);
						int size = v.size();
						for(int d=0;d<size;d++)
						{
							if(v[d]==t[ny][nx])
							{
								flag = true;
								break;
							}
						}
						if(!flag)
						{
							v.push_back(t[ny][nx]);
						}
					}
				}
			}
		}
	}
	int p = v.size();
	printf("%d", p);
	return 0;
}