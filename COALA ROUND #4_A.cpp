#include <bits/stdc++.h>
using namespace std;
long long num[2005];
int main()
{
	long long n, d;
	scanf("%lld %lld", &n, &d);
	for(int i=0;i<n;i++)
	{
		scanf(" %lld", &num[i]);
	}
	long long cnt = 0;
	for(int i=1;i<n;i++)
	{
		if(num[i]<=num[i-1])
		{
			if(num[i]==num[i-1]&&num[i]+d>num[i-1])
			{
				cnt++;
				num[i]+=d;
			}
			else
			{
				cnt += (num[i-1]-num[i])/d+1;
				num[i] += ((num[i-1]-num[i])/d+1)*d;
			}
		}
	}
	printf("%lld", cnt);
	return 0;
}
