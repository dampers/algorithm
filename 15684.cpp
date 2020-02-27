#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct lat
{
	int left;
	int right;
};

int n, m, h, mn = 33;
lat check[11][33];

int simulation()
{
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		int line = i;
		for(int j=1;j<=h;j++)
		{
			if(check[line][j].right) line++;
			else if(check[line][j].left) line--; 
		}
		if(line==i) cnt++;
        else return 0;
		//cout<<"line = "<<line<<endl;
	}
	return cnt;
}

void dfs(int pos, int dh, int lk)
{
	if(pos==dh)
	{
		int kcnt = simulation();
		if(kcnt==n) mn = min(mn, dh);
		/*cout<<"cnt = "<<kcnt<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=h;j++)
			{
				if(check[i][j].right==2) cout<<i<<' '<<j<<endl;
			}
		}
		cout<<endl;*/
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(mn==dh) return;
		for(int j=lk;j<=h;j++)
		{
			if(mn==dh) return;
			if(check[i][j].right || check[i][j].left) continue;
			else if(check[i+1][j].right) continue;
			check[i][j].right = check[i+1][j].left = 2;
			dfs(pos+1, dh, j);
			check[i][j].right = check[i+1][j].left = 0;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++)
	{
		int a, b;
		cin>>a>>b;
		check[b][a].right = 1;
		check[b+1][a].left = 1;
	}
	for(int i=0;i<=3;i++)
	{
		dfs(0, i, 1);
		if(mn!=33)
		{
			cout<<mn;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=h;j++)
			{
				if(check[i][j].right==2 || check[i][j].left==2)
				{
					check[i][j].right = 0;
					check[i][j].left = 0;
				}
			}
		}
	}
	cout<<-1;
	return 0;
}