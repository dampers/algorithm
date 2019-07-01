#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld tri;
	cin>>tri;
	tri = tri*(tri+1)/2*9;
	cout<<tri;
	return 0;
}