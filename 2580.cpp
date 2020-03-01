#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int st[10][10], size;
bool check[3][10][10], flag;
vector<pair<int, int>> v;

void backtrack(int pos)
{
	if(pos==size)
	{
		flag = true;
		return;
	}
	int y = v[pos].first, x = v[pos].second, sqcnt = (y/3)*3+(x/3);
	for(int i=1;i<=9;i++)
	{
		if(check[0][y][i]||check[1][x][i]||check[2][sqcnt][i]) continue;
		check[0][y][i] = check[1][x][i] = check[2][sqcnt][i] = true;
		st[y][x] = i;
		backtrack(pos+1);
		if(flag) return;
		st[y][x] = 0;
		check[0][y][i] = check[1][x][i] = check[2][sqcnt][i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			int block = (i/3)*3+(j/3);
			cin>>st[i][j];
			if(st[i][j]==0) v.push_back({i, j});
			else check[0][i][st[i][j]] = check[1][j][st[i][j]] = check[2][block][st[i][j]] = true;
		}
	size = v.size();
	backtrack(0);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<st[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}