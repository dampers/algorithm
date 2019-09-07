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
	lld n, sum = 1;
	cin>>n;
	for(lld i=3;i<n;i+=2)
	{
		sum *= i;
		sum %= 1000000007;
	}
	cout<<sum;

	return 0;
}