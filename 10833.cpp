#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	int n, sum = 0;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int sch, num;
		scanf(" %d %d", &sch, &num);
		sum += num%sch;
	}
	printf("%d", sum);
	return 0;
}