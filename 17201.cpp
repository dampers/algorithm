#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	int a, b, n;
	scanf("%d", &n);
	scanf("%1d%1d", &a, &b);
	int aa, bb;
	for(int i=0;i<n-1;i++)
	{
		scanf("%1d%1d", &aa, &bb);
		if(aa!=a)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}