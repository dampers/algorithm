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
	lld n, sum = 1LL;
	cin>>n;
	if(n%2) n++;
	for(int i=0;i<n/2;i++)
	{
		sum *= 2;
		sum %= 16769023;
	}
	cout<<sum;
	return 0;
}