#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, sum;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	sum += a*3600+b*60+d+c;
	a = (sum/3600)%24;
	sum %= 3600;
	b = (sum/60)%60;
	c =  sum%60;
	printf("%d %d %d", a, b, c);
	return 0;
}
