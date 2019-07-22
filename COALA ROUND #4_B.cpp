#include <bits/stdc++.h>
using namespace std;
char tmp[105];
char space[105][105];
int main()
{
	int pcnt = 0;
	int cnt = 0;
	while(scanf(" %[^\n]s", tmp)!=-1)
	{
		if(tmp[0]=='+')
		{
			pcnt++;
		}
		else if(tmp[0]=='-')
		{
			pcnt--;
		}
		else
		{
			int len = strlen(tmp);
			int plen = 0;
			for(int i=0;i<len;i++)
			{
				if(tmp[i]==':')
				{
					plen = len-i-1;
					break;
				}
			}
			cnt += pcnt*plen;
		}
	}
	printf("%d", cnt);
	return 0;
}
