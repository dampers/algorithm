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
	reverse(a, a+lena);
	reverse(b, b+lenb);
	for(int i=0;i<lena;i++)
		numa[i] = a[i]-48;
	for(int i=0;i<lenb;i++)
		numb[i] = b[i]-48;
	len = lena>lenb?lena:lenb;
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
	return 0;
}