#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[104];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	scanf(" %s", s);
	int len = strlen(s);
	int ocnt = 0, zcnt = 0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
			zcnt++;
		else if(s[i]=='1')
			ocnt++;
	}
	//printf("%d %d", ocnt, zcnt);
	if(zcnt!=ocnt)
	{
		printf("1\n%s", s);
	}
	else
	{
		printf("2\n");
		printf("%c", s[0]);
		s[0] = ' ';
		printf("%s", s);
	}
	return 0;
}