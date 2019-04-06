#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

bool prime[1000001];

int main()
{
	prime[1] = true;
	for(int i=2;i*i<1000001;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<1000001;j+=i)
			prime[j] = true;
	}
	int n, l, r;
	while(1)
	{
		scanf(" %d", &n);
		if(!n)
			break;
		int flag = 0;
		for(r=n-1;r>=n/2;r--)
		{
			if(prime[r]) continue;
			for(l=2;l<=n/2;l++)
			{
				if(prime[l]) continue;
				if(r+l==n)
				{
					flag = 1;
					break;
				}
				if(r+l>n)
					break;
			}
			if(flag) break;
		}
		if(flag) printf("%d = %d + %d\n",n ,l, r);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}