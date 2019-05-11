#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int gcd(int a, int b)
{
	if(b>a) swap(a,b);
	while(b!=0)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	int r, g;
	scanf(" %d %d", &r, &g);
	if(r==g)
	{
		for(int i=1;i*i<=r;i++)
			if(r%i==0)
			{
				if(i==r/i) printf("%d %d %d\n", i, r/i, r/i);
				else
				{
					printf("%d %d %d\n", i, r/i, r/i);
					printf("%d %d %d\n", r/i, r/(r/i), r/(r/i));
				}
			}

	}
	else
	{
		int k = gcd(r, g);
		for(int i=1;i*i<=k;i++)
			if(k%i==0)
			{
				if(i==k/i) printf("%d %d %d\n", i, r/i, g/i);
				else
				{
					printf("%d %d %d\n", i, r/i, g/i);
					printf("%d %d %d\n", k/i, r/(k/i), g/(k/i));
				}
			}
	}
	return 0;
}