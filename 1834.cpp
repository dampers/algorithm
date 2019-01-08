#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, i, sum = 0;
	scanf("%d", &n);
	for(i=1;i<n;i++)
	{
		sum += n*i+i;
	}
	printf("%lld", sum);
	return 0;
}
