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
	int a, b, c, cnt = 0;
	cin>>a>>b>>c;
	while(1)
	{
		if(abs(a-b)==1 && abs(b-c)==1)
			break;
		else if(abs(a-b)<=abs(b-c))
		{
			a = b;
			b++;
		}
		else
		{
			c = b;
			b--;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}