#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int ku[10][10];
bool row[10][10], col[10][10];
bool square[10][10];
bool flag;

void rec(int pos, vector<pair<int, int>>& v)
{
	if(pos == v.size())
	{
		flag = true;
		return;
	}
	int y = v[pos].first, x = v[pos].second;
	for(int i=1;i<=9;i++)
	{
		if(row[x][i] || col[y][i] || square[((y-1)/3)*3+((x-1)/3)][i]) continue;
		square[((y-1)/3)*3+((x-1)/3)][i] = row[x][i] = col[y][i] = true;
		ku[y][x] = i;
		rec(pos+1, v);
		if(flag) return;
		square[((y-1)/3)*3+((x-1)/3)][i] = row[x][i] = col[y][i] = false;
		ku[y][x] = 0;
	}
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> v;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			scanf(" %1d", &ku[i][j]);
			if(ku[i][j] == 0)
			{
				v.push_back({i, j});
				continue;
			}
			row[j][ku[i][j]] = true;
			col[i][ku[i][j]] = true;
		}
	}

	for(int i=1;i<=7;i+=3)
	{
		for(int j=1;j<=7;j+=3)
		{
			for(int ii=i;ii<i+3;ii++)
			{
				for(int jj=j;jj<j+3;jj++)
				{
					if(ku[ii][jj] == 0) continue;
					square[(i/3)*3+(j/3)][ku[ii][jj]] = true;
				}
			}
		}
	}

	rec(0, v);
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
			printf("%d", ku[i][j]);
		printf("\n");
	}

	return 0;
}