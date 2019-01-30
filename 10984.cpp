#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int t;
	scanf(" %d", &t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf(" %d", &n);
		int c, csum = 0;
		double g, sum = 0;
		for(int j=0;j<n;j++)
		{
			scanf(" %d %lf", &c, &g);
			sum += c*g;
			csum += c;
		}
		sum /= (double)csum;
		printf("%d %.2lf\n", csum, sum);
	}	
	return 0;
}