#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	clock_t start, end;
start = clock();
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n;
	scanf("%lld", &n);
	lld cnt = 0;
	if(n>=3)
	{
		cnt += n/3;
		n %= 3;
	}
	while(n>=1)
	{
		n--;
		cnt++;
	}
	if(cnt%2)
	{
		printf("SK");
	}
	else
		printf("CY");
	end = clock();
double time = (double)(end-start)/CLOCKS_PER_SEC;
	//cout<<"finished at: "<< time;
	return 0;
}