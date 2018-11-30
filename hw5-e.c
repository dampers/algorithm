#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct spoint
{
	char stri[11];
	int point;
};
int main()
{
	struct spoint s[11];
	int n, i, t;
	scanf(" %d\n", &n);
	for(i=1;i<=n;i++)
	{
		s[i].point = 0;
		gets(s[i].stri);
		int len = strlen(s[i].stri);
		int j;
		for(j=0;j<len;j++)
		{
			if(s[i].stri[j]>='a'&&s[i].stri[j]<='z')
			{
				s[i].point += (int)(s[i].stri[j])-96;
			}
		}
	}
	scanf(" %d", &t);
	printf("%d", s[t].point);
	return 0;
}