#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int circle[100];
int gcd(int a, int b)
{
	int tmp;
	if(b>a) swap(a,b);
	while(b!=0)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &circle[i]);
	for(int i=1;i<n;i++)
	{
		int k = gcd(circle[i], circle[0]);
		printf("%d/%d\n",circle[0]/k, circle[i]/k);
	}
	return 0;
}