#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define MOD 1000000007
typedef long long lld;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

lld binary_exp(lld k, lld times)
{
	lld ret = 1;
	while(times)
	{
		if(times & 1)
		{
			ret = (ret * k) % MOD;
		}
		k = (k * k) % MOD;
		times >>= 1;
	}
	return ret;
}

lld factorial(lld k)
{
	lld ret = 1;
	for(lld i=1;i<=k;i++)
		ret = (ret * i) % MOD;
	return ret;
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	lld n, k;
	cin >> n >> k;
	lld nf = factorial(n), kf = factorial(k), jf = factorial(n-k);
	kf = (kf * jf) % MOD;
	kf = binary_exp(kf, MOD-2);
	cout << (nf * kf) % MOD;
	return 0;
}