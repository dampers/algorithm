#include<bits/stdc++.h>
using namespace std;
int n, sum = 0;
int num[16], check[16];
int flag = 0;
void dia(int pos)
{
	int tmp = sum%360;
	if(pos==n)
	{
		if(flag==1) return;
		else if(tmp==0)
		{
			flag = 1;
			printf("YES");
		}
		return;
	}
	sum += num[pos];
	dia(pos+1);
	if(flag==1) return;
	sum -= 2*num[pos];
	dia(pos+1);
	if(flag==1) return;
	sum += num[pos];
	return;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf(" %d", &num[i]);
	dia(0);
	if(flag==0) printf("NO");
	return 0;
}
