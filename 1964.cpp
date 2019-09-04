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
	lld n, cnt = 5;
	cin>>n;
	for(int i=2;i<=n;i++)
		cnt+=3*i+1;
	cout<<cnt%45678;
	return 0;
}