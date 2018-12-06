#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

char code[501];
char dco[501] = "END";

int main(){
	while(1)
	{
		scanf(" %[^\n]s", code);
		if(!strcmp(code, dco)) break;
		for(int i=strlen(code)-1;i>=0;i--)
		{
			printf("%c", code[i]);
		}
		printf("\n");
	}
	return 0;
}