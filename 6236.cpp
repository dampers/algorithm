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
 
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	int left = 0, right = INT_MAX;
	int ans = INT_MAX;
	while(left < right)
	{
		int mid = (left+right)/2;
		int cnt = 0, storage = 0;
		for(int i=0;i<n;i++)
		{
			if(v[i] > mid)
			{
				cnt = m+1;
				break;
			}
			if(storage + v[i] > mid)
			{
				cnt++;
				storage = v[i];
			}
			else storage += v[i];
		}
		if(storage) cnt++;
		if(cnt > m) left = mid+1;
		else
		{
			ans = min(ans, mid);
			right = mid;
		}
	}
	cout << ans;

	return 0;
}
