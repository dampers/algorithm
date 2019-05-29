#include <bits/stdc++.h>
using namespace std;

bool etc[1001];
int num[4];
int s;
bool flag;

void f(int pos)
{
	if(pos==3)
	{
		if(num[0]+num[1]+num[2]==s)
		{
			flag = true;
			printf("%d %d %d\n", num[0], num[1], num[2]);
			return;
		}
		return;
	}
	if(flag) return;
	for(int i=0;i<s;i++)
	{
		if(!etc[i])
		{
			num[pos] = i;
			f(pos+1);
		}
	}
}

int main()
{
	etc[0] = true;
	etc[1] = true;
	for(int i=2;i<1001;i++)
		for(int j=i+1;j<1001;j++)
			if(!etc[j] && j%i==0)
				etc[j] = true;
	int n;
	scanf("%d", &n);
	for(int z=0;z<n;z++)
	{
		flag = false;
		scanf("%d", &s);
		f(0);
		if(!flag) printf("0");
	}			
	return 0;
}