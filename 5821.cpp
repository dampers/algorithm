#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int X[100001];
int psum[100001];

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, L, B;
	cin >> R >> L >> B;
	for(int i=1;i<=R;i++)
	{
		cin >> X[i];
		psum[i] = psum[i-1] + X[i];
	}

	int ans = 0;
	for(int i=1;i<=R;i++)
	{
		int s = i;
		int e = R;
		while(s <= e)
		{
			int mid = (s+e)/2;
			int k = (i+mid) / 2;
			int tmp = 0;
			tmp += psum[mid] - psum[k] - (X[k] * (mid-k));
			tmp += X[k] * (k-i) - (psum[k-1]-psum[i-1]);
			if(tmp <= B)
			{
				ans = max(ans, mid-i+1);
				s = mid+1;
			}
			else e = mid-1;
		}
	}
	cout << ans;
	

	return 0;
}
