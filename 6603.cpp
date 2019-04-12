#include <bits/stdc++.h>
#define swap(a,b) a^=b^=a^=b
using namespace std;
typedef long long lld;
int ans[15], num[15];
bool check[15];
int n;

void f(int pos)
{
	if(pos==6)
	{
		for(int i=0;i<6;i++)
			printf("%d ", ans[i]);
		printf("\n");
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if((pos==0 || ans[pos-1]<num[i]) && check[i]==false)
		{
			check[i] = true;
			ans[pos] = num[i];
			f(pos+1);
			check[i] = false;
		}
	}
}
int main()
{
	while(1)
	{
		scanf(" %d", &n);
		if(!n) return 0;
		for(int i=0;i<n;i++)
			scanf(" %d", &num[i]);
		sort(num, num+n);
		f(0);
		printf("\n");
	}
	return 0;
}