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
	vector<int> dpa(n+1, 0), dpb(n+1, 0);
	dpa[0] = 1;
	for(int i=1;i<=n;i++)
	{
		dpb[i] = dpa[i-1]+dpb[i-1];
		dpa[i] = dpb[i-1];
	}
	cout << dpa[n] << ' ' << dpb[n];

	return 0;
}
