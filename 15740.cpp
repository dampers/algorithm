#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char a[10001], b[10001];
int numa[10001], numb[10001], ans[10001];
int main()
{
	scanf("%s %s", a, b);
	int lena, lenb, len;
	lena = strlen(a);
	lenb = strlen(b);
	bool aflag = false, bflag = false;
	if(a[0]=='-') aflag = true;
	if(b[0]=='-') bflag = true;

	for(int i=0;i<lena;i++)
		if(a[i]!='-')
			numa[i] = a[i]-48;
	for(int i=0;i<lenb;i++)
		if(b[i]!='-')
			numb[i] = b[i]-48;
	len = lena>lenb?lena:lenb;
	if(!aflag&&!bflag)
	{
		reverse(numa, numa+lena);
		reverse(numb, numb+lenb);
		for(int i=0;i<len;i++)
		{
			ans[i] += numa[i]+numb[i];
			if(ans[i]>9)
			{
				ans[i] %= 10;
				ans[i+1]++;
			}
		}
		if(ans[len])
			len++;
		reverse(ans, ans+len);
		for(int i=0;i<len;i++)
			printf("%d", ans[i]);
	}
	else if(aflag&&bflag)
	{
		reverse(numa, numa+lena);
		reverse(numb, numb+lenb);
		len--;
		for(int i=0;i<len;i++)
		{
			ans[i] += numa[i]+numb[i];
			if(ans[i]>9)
			{
				ans[i] %= 10;
				ans[i+1]++;
			}
		}
		if(ans[len])
			len++;
		reverse(ans, ans+len);
		printf("-");
		for(int i=0;i<len;i++)
			printf("%d", ans[i]);
	}
	else
	{
		if(aflag)
		{	
			int who = 0;
			if(lena-1>lenb) who = 1;
			else if(lena-1<lenb) who = 0;
			else
			{
				for(int i=0;i<lenb;i++)
				{
					if(numa[i+1]>numb[i])
					{
						who = 1;
						break;
					}
					else if(numa[i+1]<numb[i])
					{
						who = 0;
						break;
					}
					else if(i==lenb-1) who = 2;
				}
			}
			reverse(numa, numa+lena);
			reverse(numb, numb+lenb);
			if(who==1) // a>b
			{
				printf("-");
				for(int i=0;i<lena;i++)
				{
					ans[i] += numa[i]-numb[i];
					if(ans[i]<0)
					{
						ans[i]+=10;
						ans[i+1]--;
					}
				}
				reverse(ans, ans+len);
				bool z = false;
				for(int i=0;i<len;i++)
				{
					if(ans[i]>0) z = true;
					if(z)
						printf("%d", ans[i]);
				}

			}
			else if(who==0) // a<b
			{
				for(int i=0;i<lena;i++)
				{
					ans[i] += numb[i]-numa[i];
					if(ans[i]<0)
					{
						ans[i]+=10;
						ans[i+1]--;
					}
				}
				reverse(ans, ans+len);
				bool z = false;
				for(int i=0;i<len;i++)
				{
					if(ans[i]>0) z = true;
					if(z)
						printf("%d", ans[i]);
				}
			}
			else if(who==2) //a==b
			{
				printf("0");
				return 0;
			}	
		}
		if(bflag)
		{	
			int who = 0;
			if(lena>lenb-1) who = 1;
			else if(lena<lenb-1) who = 0;
			else
			{
				for(int i=0;i<lenb;i++)
				{
					if(numa[i]>numb[i+1])
					{
						who = 1;
						break;
					}
					else if(numa[i]<numb[i+1])
					{
						who = 0;
						break;
					}
					else if(i==lenb-1) who = 2;
				}
			}
			reverse(numa, numa+lena);
			reverse(numb, numb+lenb);
			if(who==1) // a가 더 큰 경우
			{
				for(int i=0;i<lena;i++)
				{
					ans[i] += numa[i]-numb[i];
					if(ans[i]<0)
					{
						ans[i]+=10;
						ans[i+1]--;
					}
				}
				reverse(ans, ans+len);
				bool z = false;
				for(int i=0;i<len;i++)
				{
					if(ans[i]>0) z = true;
					if(z)
						printf("%d", ans[i]);
				}
			}
			else if(who==0) // b가 더 큰 경우
			{
				printf("-");
				for(int i=0;i<lenb;i++)
				{
					ans[i] += numb[i]-numa[i];
					if(ans[i]<0)
					{
						ans[i]+=10;
						ans[i+1]--;;
					}
				}
				reverse(ans, ans+len);
				bool z = false;
				for(int i=0;i<len;i++)
				{
					if(ans[i]>0) z = true;
					if(z)
						printf("%d", ans[i]);
				}
			}
			else if(who==2) //a==b
			{
				printf("0");
				return 0;
			}
		}
	}
	return 0;
}