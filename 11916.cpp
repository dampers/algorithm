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

	int n;
	cin >> n;
	vector<int> base(4, 0);
	int ans = 0;
	int k, balls = 0;
	for(int i=0;i<n;i++)
	{
		cin >> k;
		if(k == 1)
		{
			balls++;
			if(balls == 4)
			{
				if(base[3] == 1 && base[2] == 1 && base[1] == 1) ans++;
				else if(base[2] == 1 && base[1] == 1) base[3] = 1;
				else if(base[1] == 1) base[2] = 1;
				base[1] = 1;
				balls = 0;
			}
		}
		else if(k == 2)
		{
			balls = 0;
			if(base[3] == 1 && base[2] == 1 && base[1] == 1) ans++;
			else if(base[2] == 1 && base[1] == 1) base[3] = 1;
			else if(base[1] == 1) base[2] = 1;
			base[1] = 1;
		}
		else
		{
			balls++;
			if(base[3] == 1)
			{
				ans++;
				base[3] = 0;
			}
			if(base[2] == 1)
			{
				base[3] = 1;
				base[2] = 0;
			}
			if(base[1] == 1)
			{
				base[1] = 0;
				base[2] = 1;
			}
			if(balls == 4)
			{
				balls = 0;
				base[1] = 1;
			}
		}
		//cout << base[1] << ' ' << base[2] << ' ' << base[3] << ' ' << balls << endl;
	}
	cout << ans;

	return 0;
}
