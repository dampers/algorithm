#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	lld n, sum = 0, ttmp = 0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		lld tmp;
		cin>>tmp;
		tmp *= i;
		tmp -= ttmp;
		printf("%lld ", tmp);
		ttmp += tmp;
	}
	return 0;
}