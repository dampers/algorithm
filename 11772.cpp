#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	int n;
	scanf(" %d", &n);
	lld tmp, sum = 0;
	for(int i=0;i<n;i++)
	{
		scanf(" %lld", &tmp);
		lld pot;
		pot = tmp%10;
		tmp /= 10;
		sum += pow(tmp, pot);
	}
	printf("%lld", sum);
	return 0;
}