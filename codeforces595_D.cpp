#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[200005];
int day[200005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	queue<int> que;
	while(q--)
	{
		int n;
		cin>>n;
		memset(day, 0, sizeof(day));
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(day[i]) continue;
			int k = num[num[i]], cnt = 1;
			if(num[i]==i)
			{
				day[i] = 1;
				continue;
			}
			while(num[i]!=k)
			{
				cnt++;
				que.push(k);
				k = num[k];
				//cout<<k<<endl;
			}
			int size = que.size();
			while(size--)
			{
				int tmp = que.front();
				que.pop();
				day[tmp] = cnt;
			}
		}
		for(int i=1;i<=n;i++)
			cout<<day[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}