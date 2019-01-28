#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int p[101][2];

int gcd(int a, int b)
{
	int c = a%b;
	while(c!=0)
	{
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}

int main()
{
	int x, y;
	scanf(" %d %d", &x, &y);
	int n, g = y;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d", &p[i][0], &p[i][1]);
		g = gcd(g, p[i][1]);
	}
	double mn = (1.0)*g/y*x;
	for(int i=0;i<n;i++)
	{
		double tmp = (1.0)*g/p[i][1]*p[i][0];
		mn = mn>tmp?tmp:mn;
	}
    mn = mn/g*1000;
	printf("%.2lf", mn);
	return 0;
}