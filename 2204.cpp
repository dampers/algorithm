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
	while(1)
	{
		cin >> n;
		if(n == 0) return 0;
		vector<pair<string, string>> v(n, {"", ""});
		for(int i=0;i<n;i++)
		{
			cin >> v[i].second;
			v[i].first = v[i].second;
			for(auto &C : v[i].first)
			{
				if('A' <= C && C <= 'Z') C = C-'A'+'a';
			}
		}
		sort(v.begin(), v.end());
		cout << v[0].second << endl;
	}

	return 0;
}