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
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		char a;
		scanf("%d %c", &tmp, &a);
		for(int j=0;j<tmp;j++)
			printf("%c", a);
		printf("\n");
	}

	return 0;
}