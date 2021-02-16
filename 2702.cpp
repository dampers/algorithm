#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << a*b/gcd(a, b) << ' ' << gcd(a, b) << endl;
	}
	return 0;
}