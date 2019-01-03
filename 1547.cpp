#include<bits/stdc++.h>
using namespace std;

int cup[4];

int main()
{
	int n, flag = 0;
	cup[1] = 1;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		if(cup[c1]==1)
		{
			cup[c1] = 0;
			cup[c2] = 1;
		}
		else if(cup[c2]==1)
		{
			cup[c2] = 0;
			cup[c1] = 1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(i==4)
		{
			flag = 1;
			break;
		}
		if(cup[i]==1)
		{
			printf("%d", i);
			break;
		}
	}
	if(flag==1) printf("-1");
	return 0;
}
