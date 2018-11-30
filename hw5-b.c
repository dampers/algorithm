#include <stdio.h>

struct ma
{
	int w;
	int h;
};
int main()
{
	struct ma m;
	scanf("%d %d", &m.w, &m.h);
	int i;
	for(i=0;i<m.h;i++)
	{
		if(i==0 || i==m.h-1)
		{
			int j;
			for(j=0;j<m.w;j++)
			{
				printf("*");
			}
		}
		else
		{
			printf("*");
			int j;
			for(j=0;j<m.w-2;j++) printf(" ");
			printf("*");
		}
		printf("\n");
	}
	return 0;
}