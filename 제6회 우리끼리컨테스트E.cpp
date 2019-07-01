#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int e[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>e[i];
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		if(e[i-1]==-1 && e[i]==1) ans++;
		else if(e[i-1]==1 && e[i]==-1) ans++;
		else if(e[i-1]*e[i]>0) ans += abs(e[i-1]-e[i]);
		else ans += abs(e[i-1]-e[i])-1;
	}
	printf("%d", ans);
	return 0;
}