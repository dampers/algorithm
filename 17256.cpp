#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, z;
	int xx, yy, zz;
	cin>>x>>y>>z;
	cin>>xx>>yy>>zz;
	cout<<xx-z<<' '<<yy/y<<' '<<zz-x;
	return 0;
}