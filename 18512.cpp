#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[2][101];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, a, b;
	cin>>x>>y>>a>>b;
	for(int i=a;i<101;i+=x)
		check[0][i] = true;
	

	return 0;
}