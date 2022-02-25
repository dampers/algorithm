#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int abc[105][105][105];

int recurr(int a, int b, int c)
{
	if(abc[a][b][c] > 0) return abc[a][b][c];
	int &ret = abc[a][b][c];
	ret = 1;
	if(a <= 50 || b <= 50 || c <= 50) return ret;
	else if(a > 70 || b > 70 || c > 70) ret = recurr(70, 70, 70);
	else if(a < b && b < c) ret = recurr(a, b, c-1) + recurr(a, b-1, c-1) - recurr(a, b-1, c);
	else ret = recurr(a-1, b, c) + recurr(a-1, b-1, c) + recurr(a-1, b, c-1) - recurr(a-1, b-1, c-1);
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	while(1)
	{
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << recurr(a+50, b+50, c+50) << endl;
	}
	return 0;
}
