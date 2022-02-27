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
 
	int n, c;
	cin >> n >> c;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];	
	}
	sort(v.begin(), v.end());
	int left = 0, right = v[n-1]-v[0]+1;
	int ans = 0;
	while(left < right)
	{
		int mid = (left+right)/2;
		int curr = v[0], cnt = 1;
		for(int i=1;i<n;i++)
		{
			if(v[i]-curr >= mid)
			{
				cnt++;
				curr = v[i];
			}
		}
		if(cnt >= c)
		{
			ans = max(ans, mid);
			left = mid+1;
		}
		else right = mid;
	}
	cout << ans;
	return 0;
}
