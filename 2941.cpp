#include<bits/stdc++.h>
using namespace std;
char calp[101];
int main()
{
	int cnt = 0;
	scanf("%s", calp);
	int len = strlen(calp);
	for(int i=0;i<len;i++)
	{
		if(calp[i]>='a'&&calp[i]<='z') cnt++;
		if(calp[i]=='n'||calp[i]=='l')
		{
			if(calp[i+1]=='j') cnt--;
		}
		if(calp[i]=='d'&&calp[i+1]=='z'&&calp[i+2]=='=') cnt--;
	}
	printf("%d", cnt);
	return 0;
}
