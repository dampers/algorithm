#include <bits/stdc++.h>
using namespace std;

char board[55][55];
int n, m, check[2][55][55];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool flag = false, returned[55][55];

int f(int y, int x)
{
	if(flag) return 0;
	check[1][y][x] = 1;
	check[0][y][x] = 1;
	int nd = (int)(board[y][x]-'0');
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i]*nd, nx = x+dx[i]*nd;
		if(ny>=n||nx>=m||ny<0||nx<0||board[ny][nx]=='H') continue;
		if(check[1][ny][nx])
		{
			if(returned[ny][nx]) check[0][y][x] = max(check[0][y][x], check[0][ny][nx]+1);
			else flag = true;
		}
		else check[0][y][x] = max(check[0][y][x], f(ny, nx)+1);
	}
	returned[y][x] = true;
	return check[0][y][x];
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %c", &board[i][j]);
	int cnt = f(0, 0);
	if(flag) printf("-1");
	else printf("%d", cnt);
	return 0;
}