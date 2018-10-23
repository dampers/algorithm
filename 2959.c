# include <stdio.h>

int num[5];

int main()
{
	int i, j, tmp;
	for(i=0;i<4;i++) scanf("%d", &num[i]);
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(num[i]>num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	printf("%d", num[0]*num[2]);
	return 0;
}
