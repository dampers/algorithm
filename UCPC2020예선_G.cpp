#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int check[200005];
int counts[200005];
int cur[200005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	cin>>n;
	for(int i=1;i<=n;i++)
		check[i] = -1;

	vector<vector<int>> v(n+1);
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		cnt = 0;
		while(1)
		{
			cin>>tmp;
			if(tmp==0) break;
			cnt++;
			v[i].push_back(tmp);
		}
		counts[i] = cnt;
	}

	int k;
	cin>>k;
	queue<int> q;
	for(int i=0;i<k;i++)
	{
		cin>>tmp;
		q.push(tmp);
		check[tmp] = 0;
	}

	int sec = 0;
	while(!q.empty())
	{
		int size = q.size();
		sec++;
		while(size--)
		{
			int p = q.front();
			q.pop();
			for(int i=0;i<(int)v[p].size();i++)
			{
				if(check[v[p][i]]!=-1) continue;
				cur[v[p][i]]++;
				if((counts[v[p][i]]%2?(counts[v[p][i]]+1)/2:counts[v[p][i]]/2)<=cur[v[p][i]])
				{
					check[v[p][i]] = sec;
					q.push(v[p][i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<check[i]<<' ';

	return 0;
}