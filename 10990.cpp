#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
			printf(" ");
		printf("*");
		for(int j=0;j<i*2-1;j++)
			printf(" ");
		if(i!=0) printf("*\n");
		else printf("\n");
	}
	return 0;
}