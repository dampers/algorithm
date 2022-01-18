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
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	priority_queue<int, vector<int>, less<int>> pq;
	for(int i=1;i<n;i++)
		pq.push(v[i]);
	int ans = 0;
	while(!pq.empty())
	{
		int curr = pq.top();
		pq.pop();
		if(curr < v[0]) break;
		curr--;
		v[0]++;
		ans++;
		pq.push(curr);
	}
	cout << ans;

	return 0;
}