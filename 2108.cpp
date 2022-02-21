#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<int> v(n, 0);
	double avr = 0.0;
	map<int, int> mp;
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		avr += v[i];
		mp[v[i]]++;
	}
	avr /= n;
	avr = round(avr);
	if(fabs(avr) <= EPS) avr = 0.0;
	sort(v.begin(), v.end());
	vector<pii> vmp(mp.begin(), mp.end());
	sort(vmp.begin(), vmp.end(), cmp);
	int fre = 0;
	if(n > 1 && vmp[0].second == vmp[1].second) fre = vmp[1].first;
	else fre = vmp[0].first;

	cout << round(avr) << endl << v[n/2] << endl << fre << endl << v[n-1]-v[0];
	return 0;
}
