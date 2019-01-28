#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int e, f, c, sum;
	scanf(" %d %d %d", &e, &f, &c);
	sum = e+f;
	int cnt = 0;
	while(sum>=c)
	{
		cnt += sum/c;
		sum = sum%c + sum/c;
	}
	printf("%d", cnt);
	return 0;
}