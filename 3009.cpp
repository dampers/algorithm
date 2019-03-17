#include<bits/stdc++.h>
using namespace std;
int x[1001], y[1001];
int main()
{
	int nx, ny;
	for(int i=0;i<3;i++)
	{
		scanf(" %d %d", &nx, &ny);
		x[nx]++;
		y[ny]++;
	}
	for(int i=0;i<=1000;i++)
		if(x[i]==1)
			printf("%d ", i);
	for(int i=0;i<=1000;i++)
		if(y[i]==1)
			printf("%d ", i);
	return 0;
}
