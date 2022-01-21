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
	if(b == 0) return a;
	return gcd(b, a%b);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int a, b;
	cin >> a >> b;
	int gcds = gcd(a, b);
	cout << a/gcds*b;

	return 0;
}