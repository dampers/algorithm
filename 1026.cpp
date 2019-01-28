#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int a[55], b[55];
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf(" %d", &a[i]);
	for(int i=0;i<n;i++)
		scanf(" %d", &b[i]);
	sort(a, a+n);
	sort(b, b+n);
	reverse(b, b+n);
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += a[i]*b[i];
	}
	printf("%d", sum);
	return 0;
}