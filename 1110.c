#include <stdio.h>
int main()
{
	int n,n1=0,n2=0,n3,nk,i=0;
	scanf("%d",&n);
	nk = n;
	while(1)
	{
		n1 = nk/10;
		n2 = nk%10;
		n3 = n1+n2;
		if(n3>=10) n3 = n3%10;
		nk = n2*10 + n3;
		i++;
		if(nk == n)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
