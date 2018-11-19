#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, t, sum;
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		sum = 0;
		for(int j=0;j<10;j++)
		{
			scanf("%d", &n);
			if(n%2) sum += n;
		}
		printf("#%d %d\n", i, sum);
	}
	
	return 0;
}
