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
	lld cnt = 2;
	cin>>n;
	while(n--)
		cnt += cnt-1;
	cout<<cnt*cnt;
	return 0;
}