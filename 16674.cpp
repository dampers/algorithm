#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[25];
int check[11];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf(" %s", s);
	int len = strlen(s);
	for(int i=0;i<len;i++)
		check[(int)s[i]-'0']++;
	if(len == check[2]+check[0]+check[1]+check[8])
	{
		if(check[2]&&check[0]&&check[1]&&check[8])
		{
			if(check[2]==check[0] && check[0]==check[1] && check[1]==check[8])
				printf("8");
			else printf("2");
		}
		else
			printf("1");
	}
	else printf("0");
	return 0;
}