#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	for(int q=0;q<n;q++)
	{
		lld x, y;
		scanf(" %lld %lld", &x, &y);
		lld a = max(x,y), b = min(x, y);
		while(a%b)
		{
			lld tmp = b;
			b = a%b;
			a = tmp;
		}
		printf("%lld\n", b);
	}
	return 0;
}
