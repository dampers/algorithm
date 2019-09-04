#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int ice[303][303];
int z[303][303];
bool check[303][303];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=n || ny<0 || nx>=m || nx<0 || check[ny][nx]) continue;
		if(ice[ny][nx])
		{
			check[ny][nx] = true;
			dfs(ny, nx);
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
			cin>>ice[i][j];
	int cnt = 0;
	for(int t=0;t<5051;t++)
	{
		int flag = 0;
		for(int i=0;i<n;i++)
		{
			if(flag==2) break;
			for(int j=0;j<m;j++)
			{
				if(ice[i][j] && !check[i][j])
				{
					flag++;
					//cout<<flag<<endl;
					if(flag==2) break;
					check[i][j] = true;
					dfs(i ,j);
				}
			}
		}
		if(flag==2)
		{
			cout<<cnt;
			return 0;
		}
		else if(flag==0)
		{
			cout<<0;
			return 0;
		}
		cnt++;
		memset(z, 0, sizeof(z));
		memset(check, false, sizeof(check));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(ice[i][j])
                    for(int k=0;k<4;k++)
                    {
                        int ny = i+dy[k], nx = j+dx[k];
                        if(ny>=n || ny<0 || nx>=m || nx<0) continue;
				        if(!ice[ny][nx]) z[i][j]++;
                    }
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				ice[i][j] -= z[i][j];
				if(ice[i][j]<0) ice[i][j] = 0;
			}

	}
	return 0;
}