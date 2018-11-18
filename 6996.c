#include <stdio.h>
#include <string.h>

char alp1[201], alp2[201];
int ask1[200], ask2[200];
int main()
{
	
	int t, i, len1, len2, cnt, j, k;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		cnt = 0;
		scanf("%s %s", alp1, alp2);
		len1 = strlen(alp1);
		len2 = strlen(alp2);
		for(j=0;j<len1;j++)
		{
			k = (int)alp1[j];
			ask1[k]++;
		}
		for(j=0;j<len2;j++)
		{
			k = (int)alp2[j];
			ask2[k]++;
		}
		for(j=0;j<200;j++)
		{
			if(ask1[j]==ask2[j])
			{
				cnt++;
			}
		}
		if(cnt==200)
		{
			printf("%s & %s are anagrams.\n",alp1, alp2);
			for(j=0;j<200;j++)
			{
				alp1[j] = '\0';
				alp2[j] = '\0';
				ask1[j] = 0;
				ask2[j] = 0;
			}
		}
		else
		{
			printf("%s & %s are NOT anagrams.\n",alp1, alp2);
			for(j=0;j<200;j++)
			{
				alp1[j] = '\0';
				alp2[j] = '\0';
				ask1[j] = 0;
				ask2[j] = 0;
			}
		}
	}
	return 0;
}
