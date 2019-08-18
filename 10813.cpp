#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int ball[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<101;i++) ball[i] = i;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int a, b;
		scanf(" %d %d", &a, &b);
		int tmp = ball[a];
		ball[a] = ball[b];
		ball[b] = tmp;
	}
	for(int i=1;i<=n;i++)
		printf("%d ", ball[i]);
	return 0;
}