#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[10];
int main()
{
	int n;
	while(scanf("%1d", &n)==1)
	{
		if(n==9)
			num[6]++;
		else
			num[n]++;
	}
	if(num[6]%2)
		num[6] = (num[6]+1)/2;
	else
		num[6] /= 2;
	int mx = 0;
	for(int i=0;i<9;i++)
	{
		mx = mx>num[i]?mx:num[i];
	}
	printf("%d", mx);
	return 0;
}