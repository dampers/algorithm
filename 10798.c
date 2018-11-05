# include <stdio.h>

char alp[6][16];

int main()
{
	int i, j;
	for(i=0;i<5;i++)
	{
		scanf("%s", alp[i]);
	}
	for(i=0;i<16;i++)
	{
		for(j=0;j<5;j++)
		{
			if(alp[j][i] != '\0') printf("%c", alp[j][i]);
		}
	}
	return 0;
}
