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
	int a, b, c;
	cin>>a>>b>>c;
	c %= 4;
	for(int i=0;i<c;i++)
		a = a^b;
	cout<<a;
	return 0;
}