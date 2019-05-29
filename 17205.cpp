#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char password[11];
char alp[27];
char ans[11];
int n;
lld cnt = 0;
void f(int pos, int k)
{
	if(pos==n)
	{
		if(!strcmp(password, ans))
		{
			printf("%lld", cnt);
			return;
		}
		cnt++;
	}
}

int main()
{
	for(int i=0;i<26;i++)
		alp[i] = 'a'+i;
	scanf("%d", &n);

	return 0;
}