#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

vector<int> v[1001];
int cnt[1001];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int k;
		cin>>k;
		int tmpa, tmpb;
		cin>>tmpa;
		for(int j=1;j<k;j++)
		{
			cin>>tmpb;
			if(find(v[tmpa].begin(), v[tmpa].end(), tmpb)==v[tmpa].end())
			{
				v[tmpa].push_back(tmpb);
				cnt[tmpb]++;
			}
			tmpa = tmpb;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(cnt[i]==0) q.push(i);
	vector<int> prv;
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int tmp = q.front();
			prv.push_back(tmp);
			q.pop();
			int psize = v[tmp].size();
			for(int j=0;j<psize;j++)
				if(--cnt[v[tmp][j]]==0) q.push(v[tmp][j]);
		}
	}
	int prvsize = prv.size();
	if(prvsize==n)
	{
		for(int i=0;i<prvsize;i++)
			cout<<prv[i]<<endl;
	}
	else cout<<0;
	return 0;
}