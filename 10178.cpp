#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
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
		int a, b;
		scanf(" %d %d", &a, &b);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a/b, a%b);
	}
	return 0;
}