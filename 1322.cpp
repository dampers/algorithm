#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld x, k, y = 0LL;
	cin>>x>>k;
	int bk = 0;
	while(k>0)
	{
		while(x&1)
		{
			bk++;
			x>>=1;
		}
		if(k&1)
		{
			y |= (1LL<<bk);
		}
		bk++;
		k >>= 1;
		x >>= 1;
	}
	cout<<y;
	return 0;
}