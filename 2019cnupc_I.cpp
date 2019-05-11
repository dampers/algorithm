#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	int cnt = 0;
	while(1)
	{
		if(cnt>=20) break;
		if(n==1)
		{
			printf("YES");
			return 0;
		}
		else if(n%3==0)
		{
		//	printf("n%3==0\n");
			n /= 3;
		}
		else if(n%3==1)
		{
		//	printf("n%3==1\n");
			n --;
			n /= 3;
		}
		cnt++;
	//	printf("%d\n", n);
	}
	printf("NO");
	return 0;
}