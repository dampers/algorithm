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
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		double k;
		scanf(" %lf", &k);
		printf("$%.2lf\n", k*0.8);
	}
	return 0;
}