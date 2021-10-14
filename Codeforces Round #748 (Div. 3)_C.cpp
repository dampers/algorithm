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
		int n, k;
		cin >> n >> k;
		vector<int> v(k, 0);
		for(int i=0;i<k;i++)
			cin >> v[i];
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0, step = 0;
		for(int i=0;i<k;i++)
		{
			if(n-step > n-v[i])
			{
				ans++;
				step += n-v[i];
			}
			else break;
			//cout << step << ' ';
		}
		cout << ans << endl;

	}

	return 0;
}