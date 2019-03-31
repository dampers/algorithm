#include <bits/stdc++.h>
using namespace std;

struct coord
{
	double x, y;
};

coord cor[101];

int main()
{
	int n;
	scanf(" %d", &n);
	double mx = 0, d, xx, yy, tmp, mxx1, myy1, mxx2, myy2;
	for(int i=0;i<n;i++)
		scanf(" %lf %lf", &cor[i].x, &cor[i].y);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			xx = pow(abs(cor[i].x-cor[j].x), 2);
			yy = pow(abs(cor[i].y-cor[j].y), 2);
			tmp = pow((xx+yy), 0.5);
			if(mx<tmp)
			{
				mxx1 = cor[i].x;
				myy1 = cor[i].y;
				mxx2 = cor[j].x;
				myy2 = cor[j].y;
				mx = tmp;
			}
		}
	}
	xx = mxx1-(mxx1-mxx2)/2;
	yy = myy1-(myy1-myy2)/2;
	mx /= 2;
	printf("%.3lf %.3lf %.3lf", xx, yy, mx);
	return 0;
}