#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[300];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf(" %[^\n]s", s);
	int len = strlen(s);
	int hcnt = 0, scnt = 0;
	for(int i=0;i<len-2;i++)
	{
		if(!strncmp(s+i, ":-)",3)) hcnt++;
		else if(!strncmp(s+i, ":-(",3)) scnt++;
	}
	if(hcnt+scnt==0) printf("none");
	else if(hcnt==scnt) printf("unsure");
	else if(hcnt>scnt) printf("happy");
	else printf("sad");
	return 0;
}