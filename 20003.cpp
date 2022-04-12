#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int gcd(int a, int b)
{
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<pii> v(n);
	int tmp;
	for(int i=0;i<n;i++)
	{
	    cin >> v[i].first >> v[i].second;
	    tmp = gcd(v[i].first, v[i].second);
	    v[i].first /= tmp;
	    v[i].second /= tmp;
	}
	int mlcm = v[0].second;
	for(int i=1;i<n;i++)
	{
	    tmp = gcd(mlcm, v[i].second);
	    mlcm = mlcm * v[i].second / tmp;
	}
	
	int mgcd = v[0].first * (mlcm/v[0].second);
	for(int i=0;i<n;i++)
	{
	    v[i].first = v[i].first * (mlcm/v[i].second);
	    mgcd = gcd(mgcd, v[i].first);
	}
	cout << mgcd << ' ' << mlcm << endl;
	
	
	return 0;
}
