#include<bits/stdc++.h>
using namespace std;
int n, sum = 0;
int num[16], check[16];
int flag = 0;
void dia(int pos)
{
	if(flag==1) return;
	for(int i=0;i<n;i++)
	{
		if(check[i]==0)
		{
			check[i] = 1;
			if(flag==1) return;
			sum -= 2*num[i];
			if(sum%360 == 0)
			{
				flag = 1;
				return;
			}
			dia(pos+1);
			sum += 2*num[i];
			if(sum%360 == 0)
			{
				flag = 1;
				return;
			}
			check[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &num[i]);
		sum += num[i];
	}
	dia(0);
	if(flag) printf("YES");
	else printf("NO");
	return 0;
}
