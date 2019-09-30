#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, n, m, cnt = 0;
	cin>>a>>b>>n>>m;
	queue<int> q;
	q.push(n);
	check[n] = true;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int k = q.front();
			q.pop();
			if(k==m)
			{
				cout<<cnt;
				return 0;
			}
			if(k+1<=100000 && !check[k+1])
			{
				q.push(k+1);
				check[k+1] = true;
			}
			if(k-1>=0 && !check[k-1])
			{
				q.push(k-1);
				check[k-1] = true;
			}
			if(k+a<=100000 && !check[k+a])
			{
				q.push(k+a);
				check[k+a] = true;
			}
			if(k-a>=0 && !check[k-a])
			{
				q.push(k-a);
				check[k-a] = true;
			}
			if(k+b<=100000 && !check[k+b])
			{
				q.push(k+b);
				check[k+b] = true;
			}
			if(k-b>=0 && !check[k-b])
			{
				q.push(k-b);
				check[k-b] = true;
			}
			if(k*a<=100000 && !check[k*a])
			{
				q.push(k*a);
				check[k*a] = true;
			}
			if(k*b<=100000 && !check[k*b])
			{
				q.push(k*b);
				check[k*b] = true;
			}
		}
		cnt++;
	}
	return 0;
}