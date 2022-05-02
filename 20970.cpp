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

	int N, K;
	cin >> N >> K;
	vector<int> v(N+1, 0);
	for(int i=1;i<=N;i++)
		v[i] = i;

	vector<vector<int>> change(N+1, vector<int>());
	int a, b;
	for(int i=0;i<K;i++)
	{
		cin >> a >> b;
		change[v[a]].emplace_back(b);
		change[v[b]].emplace_back(a);
		swap(v[a], v[b]);
	}
	for(int i=1;i<=N;i++)
	{
		if(change[i].empty()) change[i].emplace_back(i);
	}

	/*for(int i=1;i<=N;i++)
	{
		cout << i << " : ";
		for(auto K : change[i])
		{
			cout << K << ' ' ;
		}
		cout << endl;
	}*/
	vector<int> ans(N+1, 0);
	fill(v.begin(), v.end(), 0);
	for(int i=1;i<=N;i++)
	{
		set<int> st;
		int curr = i, prev = 0;
		if(v[curr])
		{
			ans[curr] = ans[v[curr]];
			continue;
		}
		st.insert(curr);
		while(1)
		{
			v[prev] = i;
			if(v[curr]) break;
			for(int K : change[curr]) st.insert(K);
			prev = curr;
			curr = change[curr].back();
		}
		ans[i] = st.size();
	}
	for(int i=1;i<=N;i++)
		cout << ans[i] << endl ;

	return 0;
}
