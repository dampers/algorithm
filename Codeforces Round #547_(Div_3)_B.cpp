#include <bits/stdc++.h>

using namespace std;
int day[500005];
int main()
{
	int n;
	scanf("%d", &n);
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &day[i]);
		day[i+n] = day[i];
	}
	int rest = 0;
	for(int i=0;i<2*n;i++)
	{
		if(day[i] && day[i+1])
		{
			if(rest==0)
				rest+=2;
			else
				rest++;
			mx = mx<rest?rest:mx;
		}
		else if(day[i])
		{
			rest = 1;
		}
		else
			rest = 0;
		mx = mx<rest?rest:mx;
		//printf("mx = %d rest = %d\n", mx, rest);		
	}
	printf("%d", mx);
	return 0;
}
