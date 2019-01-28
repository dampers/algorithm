#include<bits/stdc++.h>
using namespace std;
bool prime[10001];
int main()
{
	for(int i=2;i*i<=10000;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<=10000;j+=i)
		{
			prime[j]=true;
		}
	}
	prime[1] = true;
	int m, n, mn=10000, sum = 0, flag = 0;
	scanf(" %d  %d", &m, &n);
	for(int i=m;i<=n;i++)
	{
		if(prime[i]==false)
		{
			mn = mn>i?i:mn;
			flag=1;
			sum += i;
		 }
	}
	if(flag)
	{
		printf("%d\n%d", sum, mn);
	}
	else printf("-1");
	return 0;
}