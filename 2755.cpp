#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[105], hk[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, hsum = 0, sum = 0;
	scanf("%lld", &n);
	for(int i=0;i<n;i++)
	{
		lld h, k;
		scanf(" %s %lld %s", s, &h, hk);
		hsum += h;
		k = ('E'-hk[0])*100000;
		if(hk[0]=='F') k = 0;
		if(hk[1]=='+') k += 30000;
		else if(hk[1]=='-') k -= 30000;
		//printf("%lld\n", k);
		sum += k*h;
	}
	sum /= 100*hsum;
	int flag = sum%10;
	sum /= 10;
	if(flag>=5) sum++;
	double ssum = sum/(100.0);
	printf("%.2lf", ssum);
	return 0;
}