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
	char st = '!', a;
	int cnt = 0;
	while(scanf(" %c", &a)==1)
	{
		if(a!=st)
		{
			cnt += 10;
			st = a;
		}
		else cnt += 5;
	}
	cout<<cnt;
	return 0;
}