#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

using namespace std;
double distance(double a, double b)
{
	return a*a+b*b;
}

double a[1001];
double b[1001];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%lf %lf", &a[i], &b[i]);
	}
	
	double tmx = 0.0, tmn = 500000000000.0;
	double dis = 500000000000.0;
	double xx, yy;
	for(int i=0;i<n;i++)
	{
		double mx = 0.0, mn = 500000000000.0;
		for(int j=0;j<n;j++)
		{
			mx = max(mx, sqrt(distance(a[i]-a[j], b[i]-b[j])));
			mn = min(mn, sqrt(distance(a[i]-a[j], b[i]-b[j])));
		}
		if((mx+mn)/2 < dis)
		{
			dis = (mx+mn)/2;
			tmx = mx;
			tmn = mn;
			yy = b[i];
			xx = a[i];
		}
	}
	printf("%lf %lf\n", xx, yy);
	//printf("%lf", dis);

	return 0;
}