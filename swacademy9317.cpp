#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char a[100005], b[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	scanf("%d", &tc);
	for(int t=1;t<=tc;t++)
	{
		int n;
		scanf(" %d", &n);
		scanf(" %s %s", a ,b);
		int cnt = 0;
		for(int i=0;i<n;i++)
			if(a[i]==b[i]) cnt++;
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}