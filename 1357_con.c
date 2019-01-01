#include <stdio.h>

int rev(int x)
{
	int result=0;
	while(1)
	{
		result*=10;
		result+=(x%10);
		if(x/10==0) break;
		x/=10;
	}
	
	return result;
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", rev(rev(x)+rev(y)));
	
	return 0;
}
