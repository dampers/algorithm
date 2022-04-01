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
	set<int> A, B;
	int a, b;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		A.insert(a);
	}
	for(int i=0;i<m;i++)
	{
		cin >> b;
		B.insert(b);
	}
	vector<int> ans;
	for(auto &K : A)
	{
		if(B.find(K) == B.end())
		{
			ans.push_back(K);
		}
	}
	cout << ans.size() << endl;
	for(int &K : ans)
		cout << K << ' ';

	return 0;
}
