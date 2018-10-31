#include <stdio.h>
 
int s[3];

int main()
{
	int i, tmp, j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d", &tmp);
			s[i] += tmp;
		}
	}
	printf("%d", s[0]>=s[1]?s[0]:s[1]);
    return 0;
}
