#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--; y--;
		vector<bool> check(n, false);
		int tmp = x%n, cnt = x+1;
		while(1)
		{
			if(check[tmp])
			{
				cout << -1 << endl;
				break;
			}
			check[tmp] = true;
			if(tmp == y)
			{
				cout << cnt << endl;
				break;
			}
			cnt += m;
			tmp = (tmp+m)%n;
		}
	}
	return 0;
}