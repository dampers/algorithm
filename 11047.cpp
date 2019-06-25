#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int coin[11];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>coin[i];
	reverse(coin, coin+n);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		while(k>=coin[i])
		{
			cnt++;
			k -= coin[i];
		}
	}
	printf("%d", cnt);
	return 0;
}