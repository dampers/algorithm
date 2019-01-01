#include<bits/stdc++.h>

using namespace std;

int num[4];

int main()
{
	int i;
	int ind = 0;
	for(i=0;i<3;i++)
	{
		scanf("%d", &num[i]);
	}
	for(i=0;i<2;i++)
	{
		if(num[i]+1>=num[i+1])
		{
			ind = i+1;
		}
	}
	int sum;
	if(ind == 0)
	{
		sum = 3*num[0]+3;
	}
	else if(ind == 1)
	{
		sum = 3*num[1];
	}
	else if(ind == 2)
	{
		sum = 3*num[2]-3;
	}
	printf("%d", sum);
	return 0;
}
