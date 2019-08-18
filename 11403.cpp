#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int table[101][101];
bool visit[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>table[i][j];
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		memset(visit, false, sizeof(visit));
		for(int j=0;j<n;j++)
		{
			if(table[i][j])
			{
				q.push(j);
				visit[j] = true;
			}
		}
		while(!q.empty())
		{
			int size = q.size();
			while(size--)
			{
				int x = q.front();
				q.pop();
				for(int j=0;j<n;j++)
				{
					if(table[x][j] && !visit[j])
					{
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			if(visit[j])
				table[i][j] = 1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<table[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}