#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld num[10005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		num[i] = num[i-1]+tmp;
	}
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(num[j]-num[i]==m)
			{
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}