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

	uint64_t left = 0, right = UINT_MAX;
	while(left < right)
	{
		uint64_t mid = (left+right)/2;
		if(mid*mid < n) left = mid+1;
		else right = mid;
	}
	cout << left;


	return 0;
}
