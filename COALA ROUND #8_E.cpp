#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int track[1005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin>>a>>b;
		int mx = max(a, b);
		int mn = min(a, b);
		for(int j=mn;j<=mx;j++)
			track[j]++;
	}
	int ans = -1;
	for(int i=x;i<1005;i++)
	{
		if(track[i]==n)
		{
			ans = abs(x-i);
			break;
		}
	}
	for(int i=x;i>=0;i--)
	{
		if(track[i]==n)
		{
			if(ans>-1) ans = min(ans, abs(x-i));
			else ans = abs(x-i);
			break;
		}
	}
	cout<<ans;
	return 0;
}