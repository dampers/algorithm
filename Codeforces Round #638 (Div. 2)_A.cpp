#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[33];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		lld two = 2LL;
		for(int i=1;i<=n;i++)
		{
			num[i] = two;
			two *= 2;
		}
		lld asum = num[n], bsum = 0LL;
		if(n==2)
		{
			cout<<2<<endl;
			continue;
		}
		for(int i=n-1;i>=n/2;i--)
			bsum += num[i];
		for(int i=1;i<n/2;i++)
			asum += num[i];
		cout<<abs(asum-bsum)<<endl;
	}
	return 0;
}