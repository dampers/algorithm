#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[1005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<1000;i++)
		scanf(" %1d", &num[i]);
	lld summx = 0;
	for(int i=0;i<1000-4;i++)
	{
		lld sum = num[i];
		for(int j=i+1;j<i+5;j++)
			sum *= num[j];
		if(summx<sum)
		{
			summx = sum;
		}
	}
	printf("%lld", summx);
	return 0;
}