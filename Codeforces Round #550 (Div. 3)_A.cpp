#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char p[101];
int alp[28];
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int flag = 0;
		for(int j=0;j<101;j++)
			p[j] = '\0';
		for(int j=0;j<26;j++)
			alp[j] = 0;
		scanf(" %s", p);
		int len = strlen(p);
		if(len==1)
		{
			printf("Yes\n");
			p[0] = '\0';
			continue;
		}
		for(int j=1;j<len;j++)
		{
			if(p[j-1]=='a'&&p[j]=='z')
			{
				flag = 1;
				break;
			}
			if(p[j-1]=='z'&&p[j]=='a')
			{
				flag = 1;
				break;
			}
		}
		sort(p, p+len);
		int mn = 101, mx = 0;
		for(int j=0;j<len;j++)
		{
			alp[p[j]-'a']++;
			if(alp[p[j]-'a']>1)
			{
				flag = 1;
				break;
			}
		}
		/*for(int j=0;j<26;j++)
			printf("%d ",alp[j]);
		cout<<endl;*/
		for(int j=0;j<26;j++)
		{
			if(alp[j]==1&&j<mn)
			{
				mn = j;
			}
			if(alp[j]==1&&j>mx)
			{
				mx = j;
			}
		}
		for(int j=mn;j<mx;j++)
		{
			if(alp[j]!=1 || alp[j+1]!=1)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}