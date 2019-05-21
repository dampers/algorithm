#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	int n;
	scanf("%d", &n);
	if(n%2==0)
	{
		printf("I LOVE CBNU");
		return 0;
	}
	for(int i=0;i<n;i++) printf("*");
	printf("\n");
	int flag = 0;
	for(int i=n/2+1;i>0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				printf("*");
				flag++;
			}
			else if((n-i+1)==j)
			{
				printf("*");
				flag++;
			}
			else if(flag && i==n/2+1) continue;
			else if(flag<2) printf(" ");
		}
		flag = 0;
		printf("\n");
	}
	return 0;
}