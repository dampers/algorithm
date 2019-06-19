#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;
char tstring[1000002];
char astring[1000002];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %s %s", astring, tstring);
		int tmp = 0, len = strlen(astring);
		if(len>strlen(tstring))
		{
			printf("NO\n");
			continue;
		}
		else if(astring[0]!=tstring[0])
		{
			printf("NO\n");
			continue;
		}
		else if(!strcmp(astring, tstring))
		{
			printf("YES\n");
			continue;
		}
		int tlen = strlen(tstring), pcnt = 1;
		int flag = 0;
		for(int j=1;j<tlen;j++)
		{
			if(pcnt<len && tstring[j]==astring[pcnt])
				pcnt++;
			else if(tstring[j-1]!=tstring[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("NO\n");
		else if(pcnt!=len)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}