#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int q = 0, w = 0;
	int cnt = 0, mn = m/n;
	if(m==n)
	{
		cnt = 0;
	}
	else if(m%n!=0)
	{
		cnt = -1;
	}
	else if(mn%2!=0 && mn%3!=0)
	{
		cnt = -1;
	}
	else
	{
		while(mn%6==0)
		{
			cnt+=2;
			mn /= 6;
		}
		while(mn%2==0)
		{
			cnt++;
			mn /= 2;
		}
		while(mn%3==0)
		{
			cnt++;
			mn /= 3;
		}
		if(mn!=1)
			cnt = -1;
	}
	printf("%d", cnt);
	return 0;
}
