#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int _lower_bound(int left, int right, int key, vector<int>& v)
{
	while(left < right)
	{
		int mid = (left+right)/2;
		if(v[mid] < key) left = mid+1;
		else right = mid;
	}
	return left;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pii> v(n, {0, 0});
	for(int i=0;i<n;i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	
	vector<int> LIS(n, 0), pos(n, 0);
	int lisp = 0;
	LIS[lisp] = v[0].second;
	for(int i=1;i<n;i++)
	{
		if(LIS[lisp] < v[i].second)
		{
			LIS[++lisp] = v[i].second;
			pos[i] = lisp;
		}
		else
		{
			int lp = _lower_bound(0, lisp, v[i].second, LIS);
			LIS[lp] = v[i].second;
			pos[i] = lp;
		}
	}
	cout << n-lisp-1 << endl;
	vector<int> ans;
	int flp = lisp;
	for(int i=n-1;i>=0;i--)
	{
		if(pos[i] == flp) flp--;
		else ans.push_back(v[i].first);
	}
	sort(ans.begin(), ans.end());
	for(int &K : ans)
		cout << K << endl;

	return 0;
}
