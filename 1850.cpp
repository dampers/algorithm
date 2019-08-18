#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld x, y;
	scanf(" %lld %lld", &x, &y);
	lld a = max(x,y), b = min(x, y);
	while(a%b)
	{
		lld tmp = b;
		b = a%b;
		a = tmp;
	}
	for(int i=0;i<b;i++)
		cout<<1;
	return 0;
}
