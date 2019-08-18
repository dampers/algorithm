#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld num[100002];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		lld tmp;
		cin>>tmp;
		num[i] = num[i-1]+tmp;
	}
	if(num[n]<m) cout<<0;
	else
	{
		int cnt = 2*n;
		for(int s=0, e=1;s<n, e<=n;)
		{
			if(num[e]-num[s]>=m)
			{
				cnt = min(cnt, e-s);
				s++;
			}
			else e++;
		}
		cout<<cnt;
	}
	return 0;
}