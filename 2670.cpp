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
	vector<double> v(n, 0.0);
	double mx = 0.0;
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	double tmp = 1.0;
	cout.precision(3);
    cout << fixed;

	for(int i=0;i<n;i++)
	{
		if(tmp * v[i] < v[i]) tmp = v[i];
		else tmp *= v[i];
		mx = max(mx, tmp);
	}
	cout << mx;
	return 0;
}
