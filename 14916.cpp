#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int n, ans = 0;
	scanf(" %d", &n);
	int m = n;
	if(n>=5)
	{
		ans = n/5;
		n = n%5;
	}
	if(n%2==0)
	{	
		ans += n/2;
	}
	else
	{
		if(n+5==8 || n+5==6)
		{
			n += 5;
			ans--;
		}
		if(n>m)
			ans = -1;
		else if(n%2==0)
		{	
			ans += n/2;
		}
		else
			ans = -1;
	}
	printf("%d", ans);
	return 0;
}