#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int l, c, p, s;
bool check[15];
char ans[16], alp[16];

void f(int pos, int k)
{
	if(pos==l)
	{
		if(p>0 && s>1) printf("%s\n", ans);
		return;
	}
	for(int i=k;i<c;i++)
	{
		if(!check[i])
		{
			check[i] = true;
			if(alp[i]=='a'||alp[i]=='e'||alp[i]=='i'||alp[i]=='o'||alp[i]=='u')
			{
				p++;
				ans[pos] = alp[i];
				f(pos+1, i+1);
				p--;
			}
			else
			{
				s++;
				ans[pos] = alp[i];
				f(pos+1, i+1);
				s--;
			}
			check[i] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &l, &c);
	for(int i=0;i<c;i++)
		scanf(" %c", &alp[i]);
	sort(alp, alp+c);
	f(0, 0);
	return 0;
}