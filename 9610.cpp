#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int n;
	scanf(" %d", &n);
	int x, y;
	int q = 0, w = 0, e = 0, r = 0, t = 0;
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d", &x ,&y);
		if(x==0 || y==0) t++;
		else if(x>0 && y>0) q++;
		else if(x<0 && y>0) w++;
		else if(x<0 && y<0) e++;
		else if(x>0 && y<0) r++;
	}
	printf("Q1: %d\n", q);
	printf("Q2: %d\n", w);
	printf("Q3: %d\n", e);
	printf("Q4: %d\n", r);
	printf("AXIS: %d", t);
	return 0;
}