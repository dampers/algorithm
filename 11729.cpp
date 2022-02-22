#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void hanoi(int cnt, int start, int end, int mid)
{
	if(cnt == 1)
	{
		cout << start << ' ' << end << endl;
		return;
	}
	hanoi(cnt-1, start, mid, end);
	hanoi(1, start, end, mid);
	hanoi(cnt-1, mid, end, start);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << (1 << n)-1 << endl;
	hanoi(n, 1, 3, 2);
	return 0;
}
