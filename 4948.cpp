#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
bool prime[250000];
int main()
{
	int n;
	for(int i=2;i*i<250000;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<250000;j+=i)
			prime[j] = true;
	}
	while(1)
	{
		scanf(" %d", &n);
		if(!n) return 0;
		int cnt = 0;
		for(int i=n+1;i<=2*n;i++)
			if(prime[i] == false)
				cnt++;
		printf("%d\n", cnt);
	}
}