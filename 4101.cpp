#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int a, b;
	while(1)
	{
		scanf(" %d %d", &a, &b);
		if(a==0&&b==0)
			break;
		if(a<=b)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}