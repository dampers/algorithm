#include <stdio.h>
int main()
{
	int a,b,i,j;
	for(i=0;i<3;i++)
	{
		b=0;
		for(j=0;j<4;j++)
		{
			scanf("%1d",&a);
			b += a;
		}
		j=0;
		if(b==3) printf("A\n");
		else if(b==2) printf("B\n");
		else if(b==1) printf("C\n");
		else if(b==0) printf("D\n");
		else if(b==4) printf("E\n");
	}
	return 0;
}
