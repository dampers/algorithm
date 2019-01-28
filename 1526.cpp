#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int gnum[10];
int main()
{
	int n, k, i, sum = 0;
	scanf(" %d", &n);
	k = n;
	for(i=1;i<8;i++)
	{
		if(k<=0) break;
		else
		{
			gnum[i] = k%10;
			k /= 10;
		}
	}
	int cnt = i-1;
	printf("cnt = %d\n", cnt);
	for(int j = cnt;j>0;j--)
	{
		if(gnum[j]>=7)
		{
			if(gnum[j]*10+gnum[j-1]>=74)
				sum += 7*pow(10, j-1);
			else sum += 4*pow(10, j-1);
		}
		else if(gnum[j]>=4)
		{
			if(gnum[j]*10+gnum[j-1]>=44)
				sum += 4*pow(10, j-1);
		}
		else if(gnum[j]==0)
		{
			gnum[j-1] += 10;
		}
		else
		{
			gnum[j-1] += gnum[j]*10;
		}
		printf("sum = %d\n", sum);
	}
	printf(" %d", sum);
	return 0;
}