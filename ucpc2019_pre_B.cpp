#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[105][105];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		scanf(" %s", s[i]);
	/*for(int i=0;i<n;i++)
	{
		printf("%s", s[i]);
		printf("\n");
	}*/
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j][i]=='.')
				printf(".");
			else if(s[j][i]=='O')
				printf("O");
			else if(s[j][i]=='-')
				printf("|");
			else if(s[j][i]=='|')
				printf("-");
			else if(s[j][i]=='/')
				printf("\\");
			else if(s[j][i]=='\\')
				printf("/");
			else if(s[j][i]=='^')
				printf("<");
			else if(s[j][i]=='<')
				printf("v");
			else if(s[j][i]=='v')
				printf(">");
			else if(s[j][i]=='>')
				printf("^");
		}
		printf("\n");
	}
	return 0;
}