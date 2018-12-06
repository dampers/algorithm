#include <stdio.h>
int f(int n)
{
	if(n==0) return 0;
	if( n==1 || n==2) return 1;
	return f(n-1) + f(n-2);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	printf("%d",f(n));
	
	return 0;
}
