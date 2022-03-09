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

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n, m;
		cin >> n >> m;
		int zero = 0, tmp;
		if(n == 0) zero++;
		for(int i=n;i<=m;i++)
		{
			tmp = i;
			while(tmp)
			{
				if(tmp%10 == 0) zero++;
				tmp /= 10;
			}
		}
		cout << zero << endl;
	}

	return 0;
}
