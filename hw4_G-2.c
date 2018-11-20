# include <stdio.h>
# include <string.h>

struct run
{
	char name[21];
	int rec;	
};

struct run search[31];
char sname[21];

int main()
{
	int n, i;
	scanf(" %d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %s",search[i].name);
		scanf(" %d", &search[i].rec);
	}
	scanf(" %s", sname);
	for(i=0;i<n;i++)
	{
		if(!strcmp(sname, search[i].name))
		{
			printf("\n%d", search[i].rec);
			break;
		}
	}
	return 0;
}
