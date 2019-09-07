#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	double k;
	while(1)
	{
		scanf("%lf", &k);
		if(k<0) break;
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", k, k*0.167);
	}
	return 0;
}