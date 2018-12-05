#include<bits/stdc++.h>

using namespace std;

int tas[11][2], mtas[11][2];
int mn = 1000000000;
int check[10];
int n;

void doy (int pos, int level, int k)
{
	int i, t;
	if(pos == level)
	{
		t = abs(mtas[level][0]-mtas[level][1]);
		if(mn > t)
		{
			 mn = t;
		}
		return;
	}
	for(i=0;i<n;i++)
	{
		if(check[i]==0 && k<i)
		{
			check[i] = 1;
			mtas[level][0] *= tas[i][0];
			mtas[level][1] += tas[i][1];
			doy(pos+1, level, i);
			check[i] = 0;
			mtas[level][0] /= tas[i][0];
			mtas[level][1] -= tas[i][1];
		}
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i=0;i<11;i++) mtas[i][0] = 1;
	for(i=0;i<n;i++)
	{
		scanf(" %d %d", &tas[i][0], &tas[i][1]);
		int a = abs(tas[i][0]-tas[i][1]);
		if(mn>a) mn = a;
	}
	for(i=2;i<=n;i++)
	{
		doy(0, i, -1);
	}
	printf("%d", mn);
	return 0;
}