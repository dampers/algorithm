#include<bits/stdc++.h>
using namespace std;
char num[6], pal[6];
int main()
{
	while(1)
	{
		scanf(" %s", num);
		if(num[0]=='0') return 0;
		strcpy(pal, num);
		reverse(pal, pal+strlen(pal));
		if(strcmp(pal, num)==0) printf("yes\n");
		else printf("no\n");
		memset(num,'\0',6);
		memset(pal,'\0',6);
	}
}
