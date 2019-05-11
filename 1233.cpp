#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[3];
int main()
{
	int sum = 0;
	for(int i=0;i<3;i++)
	{	
		scanf("%d", &num[i]);
		if(num[i]%2)
			sum += num[i]/2+1;
		else sum += num[i]/2;
	}
	printf("%d", sum);
	return 0;
}