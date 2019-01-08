#include<bits/stdc++.h>

using namespace std;

char b1[81], b2[81], c[81], ans[82];

int main()
{
	scanf("%s %s", b1, b2);
	reverse(b1, b1+strlen(b1));
	reverse(b2, b2+strlen(b2));
	int len = strlen(b1)>strlen(b2)?strlen(b1):strlen(b2);
	for(int i=0;i<len;i++)
	{
		if(b1[i]=='\0') b1[i] = '0';
		if(b2[i]=='\0') b2[i] = '0';
		if(c[i]=='\0') c[i] = '0';
		if(b1[i]+b2[i]+c[i]==147)
		{
			ans[i] = '1';
			c[i+1] = '1';
		}
		else if(b1[i]+b2[i]+c[i]==146)
		{
			ans[i] = '0';
			c[i+1] = '1';
		}
		else if(b1[i]+b2[i]+c[i]==145)
		{
			ans[i] = '1';
			c[i+1] = '0';
		}
		else if(b1[i]+b2[i]+c[i]==144)
		{
			ans[i] = '0';
			c[i+1] = '0';
		}
	}
	reverse(ans, ans+strlen(ans));
	int flag = 0, lenf = strlen(ans);
	if(ans[0]=='1') flag = 1;
	for(int i=0;i<lenf;i++)
	{
		if(flag==0)
		{
			if(ans[i]=='0') flag = 1;
		}
		else printf("%c", ans[i]);
	}
	return 0;
}
