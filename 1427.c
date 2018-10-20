#include <stdio.h>
#include <string.h>
char cnum[13];

int main()
{
	int i, j, tmp, t;
	scanf("%s", cnum);
	t = strlen(cnum);
	for(i=0;i<t;i++)
	{
		for(j=1;j<t-i;j++)
		{
			if(cnum[j-1] < cnum[j])
			{
				tmp = cnum[j];
				cnum[j] = cnum[j-1];
				cnum[j-1] = tmp;
			}
		}
	}
	for(i=0;i<t;i++) printf("%d",cnum[i]-48);
	return 0;
}
