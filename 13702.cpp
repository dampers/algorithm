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
 
	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];

	int right = INT_MAX, left = 0;
	int mxl = 0;
	while(left < right)
	{
		int mid = (left+right)/2;
		int tk = 0;
		for(int i=0;i<n;i++)
		{
			tk += v[i]/mid;
		}
		if(tk < k) right = mid;
		else
		{
			left = mid+1;
			mxl = max(mxl, mid);
		}
	}
	cout << mxl;

	return 0;
}