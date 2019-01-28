#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
float p[101][2];

int main()
{
	float x, y;
	scanf(" %f %f", &x, &y);
	int n;
	float mn = (1.0)*1000/y*x;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %f %f", &p[i][0], &p[i][1]);
	}
	for(int i=0;i<n;i++)
	{
		float tmp = (1.0)*1000/p[i][1]*p[i][0];
		mn = mn>tmp?tmp:mn;
	}
	printf("%.2f", mn);
	return 0;
}