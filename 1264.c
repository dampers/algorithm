# include <stdio.h>
# include <string.h>

char alp[300];

int main()
{
	int i, cnt;
	while(1)
	{
		cnt = 0;
		gets(alp);
		if(alp[0]=='#') break;
		for(i=0;i<strlen(alp);i++)
		{
			if(alp[i]=='A'|| alp[i]=='a') cnt++;
			else if(alp[i]=='E'|| alp[i]=='e') cnt++;
			else if(alp[i]=='I'|| alp[i]=='i') cnt++;
			else if(alp[i]=='O'|| alp[i]=='o') cnt++;
			else if(alp[i]=='U'|| alp[i]=='u') cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
