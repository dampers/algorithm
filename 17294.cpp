#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char num[30];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf(" %s", num);
	bool flag = false;
	int len = strlen(num);
	if(len<3)
	{
		printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
		return 0;
	}
	for(int i=0;i<len-1;i++)
	{
		int s = ((int)num[0]-num[1]);
		if(((int)num[i]-num[i+1])!=s)
		{
			flag = true;
			break;
		}
	}
	if(!flag) printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
	else printf("흥칫뿡!! <(￣ ﹌ ￣)>");
	return 0;
}