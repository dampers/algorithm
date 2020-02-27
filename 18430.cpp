#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int n, m, mx;
int bm[6][6];
bool check[6][6];

int dfs(int y, int x, int c)
{

	for(int i=y;i<n;i++)
	{
		for(int j=x;j<m-1;j++)
		{
			int sk = 0;
			if(check[i][j]) continue;
			check[i][j] = true;
			if(i+1<n && j+1<m && !check[i][j+1] && !check[i+1][j])
			{
				check[i][j+1] = check[i+1][j] = true;
				sk = bm[i][j]*2+bm[i][j+1]+bm[i+1][j];
				mx = max(c+sk, c+sk+dfs())
				check[i][j+1] = check[i+1][j] = false;

			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>bm[i][j];

	return 0;
}