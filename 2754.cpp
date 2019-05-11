#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char h[4];

int main()
{
	scanf(" %s", h);
	double sum = 0;
	if(h[0]=='A') sum += 4;
	else if(h[0]=='B')	sum += 3;
	else if(h[0]=='C') sum += 2;
	else if(h[0]=='D') sum += 1;
	else if(h[0]=='F')
	{
		printf("0.0");
		return 0;
	}
	if(h[1]=='+') sum += 0.3;
	else if(h[1]=='-') sum -= 0.3;
	printf("%.1f", sum);
	return 0;
}