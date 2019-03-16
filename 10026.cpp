#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char paper[101][101];
bool ovisit[101][101];
bool svisit[101][101];
int scnt;
int ocnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void odfs(int y, int x, char a)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(ny>=0 && nx >=0 && ny<101 && nx<101 && paper[ny][nx]==a && !ovisit[ny][nx])
		{
			ovisit[ny][nx] = true;
			odfs(ny, nx, a);
		}
	}
}

void sdfs(int y, int x, char a)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(ny>=0 && nx >=0 && ny<101 && nx<101 && (paper[ny][nx] == 'R' || paper[ny][nx] == 'G') && !svisit[ny][nx])
		{
			svisit[ny][nx] = true;
			sdfs(ny, nx, a);
		}
	}
}

int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", paper[i]);
	char a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!ovisit[i][j])
			{
				a = paper[i][j];
				ovisit[i][j] = true;
				odfs(i, j, a);
				ocnt++;
				if(a=='B')
					scnt++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!svisit[i][j] && (paper[i][j]=='R'||paper[i][j]=='G'))
			{
				a = paper[i][j];
				svisit[i][j] = true;
				sdfs(i, j, a);
				scnt++;
			}
		}
	}
	printf("%d %d", ocnt, scnt);
	return 0;
}
