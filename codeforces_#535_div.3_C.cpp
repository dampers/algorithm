#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char lamps[200001];
int main()
{
	int n;
	cin>>n;
	scanf("%s", lamps);
	int r = 0, g = 0, b = 0, cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(lamps[i] == 'R'&&r>=1)
		{
			if(r%3==0) r = 0;
			else
			{
				if(b%3==0)
				{
					lamps[i] = 'B';
					b = 0;
				}
				else if(g%3==0)
				{
					lamps[i] = 'G';
					g = 0;
				}
				cnt++;
			}
		}
		else if(lamps[i] == 'G'&&g>=1)
		{
			if(g%3==0) g = 0;
			else
			{
				if(b%3==0)
				{
					lamps[i] = 'B';
					b = 0;
				}
				else if(r%3==0)
				{
					lamps[i] = 'R';
					r = 0;
				}
				cnt++;
			}
		}
		else if(lamps[i] == 'B'&& b>=1)
		{
			if(b%3==0) b = 0;
			else
			{
				if(r%3==0)
				{
					lamps[i] = 'R';
					r = 0;
				}
				else if(g%3==0)
				{
					lamps[i] = 'G';
					g = 0;
				}
				cnt++;
			}
		}
		if(r>=1) r++;
		if(g>=1) g++;
		if(b>=1) b++;
		if(lamps[i] == 'R' && r == 0) r++;
		else if(lamps[i] == 'G' && g == 0) g++;
		else if(lamps[i] == 'B' && b == 0) b++;
		//printf("r %d g %d b %d lamps[%d] = %c cnt = %d\n\n", r, g, b, i, lamps[i], cnt);
	}
	printf("%d\n%s", cnt, lamps);
	return 0;
}