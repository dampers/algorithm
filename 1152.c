# include <stdio.h>
# include <string.h>

char sen[1000001];

int main()
{
	int i, n, cnt = 1;
	gets(sen);
	for(i=0;i<strlen(sen);i++)
	{
		if(sen[i] == ' ') cnt++;
	}
	if(sen[0] == ' ') cnt--;
	if(sen[strlen(sen)-1] == ' ') cnt--;
	printf("%d", cnt); 
	return 0;
}
