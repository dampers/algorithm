#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		lld n, nn;
		cin >> n;
		nn = n;
		if(n < 10)
		{
			cout << n << endl;
			continue;
		}
		int cnt = 1;
		while(nn / 10)
		{
			cnt++;
			nn /= 10;
		}
		int ans = nn-1;
		lld tmp = 0;
		for(int i=0;i<cnt;i++)
		{
			tmp += nn;
			nn *= 10;
		}
		ans += (cnt-1)*9;
		if(tmp <= n) ans++;
		cout << ans << endl;
	}
	return 0;
}