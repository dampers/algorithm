#include <stdio.h>
int n;
int check[9], num[9];
void f(int pos)
{
	int i;
	if(pos==n)
	{
		for(i=0;i<n;i++)
			printf("%d ",num[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(check[i]==0)
		{
			num[pos] = i;
			check[i] = 1;
			f(pos+1);
			check[i] = 0;
		}
		
	}
}
int main()
{
	scanf("%d",&n);
	f(0);
	return 0;
}
