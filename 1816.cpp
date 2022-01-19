#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	vector<bool> prime(1000001, true);
	vector<int> primes;
	prime[0] = prime[1] = false;
	for(int i=2;i<=1000000;i++)
	{
		if(!prime[i]) continue;
		primes.push_back(i);
		for(int j=i+i;j<=1000000;j+=i)
			prime[j] = false;
	}
	
	int n;
	cin >> n;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		bool flag = true;
		for(int &K : primes)
		{
			if(tmp % K == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}