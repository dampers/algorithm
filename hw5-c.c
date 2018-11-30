#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st
{
	char name[31];
	char adr[31];
};

char srh[31];

int main()
{
	struct st stud[11];
	int i;
	for(i=0;i<10;i++)
	{
		gets(stud[i].name);
		gets(stud[i].adr);

	}
	gets(srh);
	for(i=0;i<10;i++)
	{
		if(!strcmp(stud[i].name, srh))
		{
			puts(stud[i].adr);
		}
	}
	return 0;
}