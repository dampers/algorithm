#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int vol[101];
bool check[101][1001];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s, m;
	cin>>n>>s>>m;
	for(int i=1;i<=n;i++)
		cin>>vol[i];
	queue<int> q;
	q.push(s);
	for(int i=1;i<=n;i++)
	{
		int size = q.size();
		if(size==0)
		{
			cout<<-1;
			return 0;
		}
		while(size--)
		{
			int tmp = q.front();
			q.pop();
			if(tmp+vol[i]<=m&&!check[i][tmp+vol[i]])
			{
				q.push(tmp+vol[i]);
				check[i][tmp+vol[i]] = true;
			}
			if(tmp-vol[i]>=0&&!check[i][tmp-vol[i]])
			{
				q.push(tmp-vol[i]);
				check[i][tmp-vol[i]] = true;
			}
		}
	}
	int size = q.size();
	int mx = -1;
	for(int i=0;i<size;i++)
	{
		if(mx<q.front()) mx = q.front();
		q.pop();
	}
	cout<<mx;
	return 0;
}