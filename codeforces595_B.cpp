#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[201];
int day[201];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
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
			int k = num[num[i]], cnt = 1;
			if(num[i]==i)
			{
				day[i] = 1;
				continue;
			}
			while(num[i]!=k)
			{
				cnt++;
				k = num[k];
				//cout<<k<<endl;
			}
			day[i] = cnt;
		}
		for(int i=1;i<=n;i++)
			cout<<day[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}