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
	int divs[4] = {2, 3, 5, 7};
	for(int t=1;t<=tc;t++)
	{
		cout << "Case #" << t << ": ";
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for(int k=a;k<=b;k++)
		{
			int tmp = k;
			vector<int> td(4, 0);
			int tpr = 1;
			while(tmp)
			{
				tpr *= tmp % 10;
				tmp /= 10;
			}
			if(tpr == 0)
			{
				//cout << k << endl;
				ans++;
				continue;
			}

			for(int i=0;i<4;i++)
			{
				while(tpr > 0 && tpr % divs[i] == 0)
				{
					td[i]++;
					tpr /= divs[i];
				}
			}

			/*for(int i=0;i<4;i++)
			{
				cout << td[i] << ' ';
			}
			cout << endl;*/

			int stmp = k, tsum = 0;
			while(stmp)
			{
				tsum += stmp % 10;
				stmp /= 10;
			}
			for(int i=0;i<4;i++)
			{
				while(tsum > 0 && tsum % divs[i] == 0)
				{
					td[i]--;
					tsum /= divs[i];
				}
			}


			bool flag = true;
			for(int i=0;i<4;i++)
			{
				if(td[i] < 0) flag = false;
			}
			if(flag && tsum == 1)
			{
				//cout << k << endl;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}