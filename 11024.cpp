#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf("%d", &n);
	n--;
	lld sum = 0, k;
	while(1)
	{
		char l;
		if(n) scanf("%d%c", &k, &l);
		else
		{
			sum = 0;
			while(scanf(" %d", &k)>0)
				sum += k;
			printf("%lld", sum);
			return 0;
		}
		if(l=='\n')
		{
			printf("%lld\n", sum+k);
			sum = 0;
			n--;
		}
		else
			sum += k;
	}
	return 0;
}