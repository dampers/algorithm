#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char a[204], b[204], ans[204];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	char as;
	scanf("%s %c %s", a, &as, b);
	int lena, lenb;
	lena = strlen(a);
	lenb = strlen(b);
	if(as=='+')
	{
		reverse(a, a+lena);
		reverse(b, b+lenb);
		if(lena>lenb)
		{
			for(int i=0;i<lenb;i++)
			{
				if(a[i]=='0' && b[i]=='0')
					ans[i]='0';
				else if(a[i]=='1'&&b[i]=='1')
					ans[i]='2';
				else
					ans[i]='1';
			}
			for(int i=lenb;i<lena;i++)
				ans[i] = a[i];
		}
		else
		{
			for(int i=0;i<lena;i++)
			{
				if(a[i]=='0' && b[i]=='0')
					ans[i]='0';
				else if(a[i]=='1'&&b[i]=='1')
					ans[i]='2';
				else
					ans[i]='1';
			}
			for(int i=lena;i<lenb;i++)
				ans[i] = b[i];
		}
		reverse(ans, ans+strlen(ans));
		printf("%s", ans);
	}
	if(as=='*')
	{
		int zcnt = 0;
		for(int i=0;i<lena;i++)
			if(a[i]=='0')
				zcnt++;
		for(int i=0;i<lenb;i++)
			if(b[i]=='0')
				zcnt++;
		printf("1");
		for(int i=0;i<zcnt;i++)
			printf("0");
	}
	return 0;
}