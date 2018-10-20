# include <stdio.h>

char c[10][10];

int main()
{
	int i,j,k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf("%c",&c[i][j]);
			if(j % 2 == 0 &&i % 2 == 0 && c[i][j] == 'F') k++;
			else if(i % 2 == 1 && j % 2 == 1 && c[i][j] == 'F') k++;
		}
		if(i<7) getchar();
	}
	printf("%d",k);
	return 0;
}
