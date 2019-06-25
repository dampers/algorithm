#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int source[15004];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cnt = 0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>source[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(source[i]+source[j]==m)
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}