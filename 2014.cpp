#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;
typedef unsigned long long ulld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k, n;
	cin >> k >> n;
	vector<int> prime(k, 0);
	priority_queue<lld, vector<lld>, greater<lld>> pq;
	for(int i=0;i<k;i++)
	{
		cin >> prime[i];
		pq.push(prime[i]);
	}
	sort(prime.begin(), prime.end());
	lld ans = pq.top(), mx = 1LL << 31;
	while(n--)
	{
		ans = pq.top();
		pq.pop();
		for(int i=0;i<k;i++)
		{
			lld current = ans * prime[i];
			if(current >= mx) break;
			pq.push(current);
			if(ans % prime[i] == 0) break;
		}
	}
	cout << ans;
	return 0;
}