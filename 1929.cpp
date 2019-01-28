#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
bool prime[1000001];
int main()
{
	int n, m;
	prime[1] = true;
	for(int i=2;i*i<1000001;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<1000001;j+=i)
			prime[j] = true;
	}
	scanf(" %d %d", &m, &n);
	for(int i=m;i<=n;i++)
		if(prime[i]==false) printf("%d\n", i);
	return 0;
}