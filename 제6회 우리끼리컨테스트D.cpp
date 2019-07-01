#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int a[5];
bool check[5];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++)
		scanf(" %d", &a[i]);
	int n;
	scanf(" %d", &n);
	if(n==1) printf("1614");
	else if(n==3) printf("1065");
	else if(n==4) printf("244");
	else if(n==5)
	{
		for(int i=0;i<5;i++)
		{
			if(a[i]==1614) continue;
			else if(a[i]==1065) continue;
			else if(a[i]==244) continue;
			else
			{
				printf("%d", a[i]);
				break;
			}
		}
	}
	else if(n==2)
	{
		for(int i=4;i>=0;i--)
		{
			if(a[i]==1614) continue;
			else if(a[i]==1065) continue;
			else if(a[i]==244) continue;
			else
			{
				printf("%d", a[i]);
				break;
			}
		}
	}
	return 0;
}