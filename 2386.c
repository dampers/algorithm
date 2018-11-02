# include <stdio.h>
# include <string.h>

char word[251];

int main()
{
	char Alp, alp, alp1;
	int i, cnt;
	while(1)
	{
		cnt = 0;
		gets(word);
		if(word[0] == '#') break;
		alp = word[0];
		if(alp>64 && alp<91)
		{
			Alp = alp;
			alp += 32;
		}
		else Alp = alp - 32;
		for(i=2;i<strlen(word);i++)
		{
			if(word[i]==Alp || word[i] == alp) cnt++;
		}
		printf("%c %d\n", word[0], cnt);
		for(i=0;i<strlen(word);i++) word[i] = '\0';
	}
	return 0;
}
