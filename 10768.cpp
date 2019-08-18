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
	int a, b;
	scanf("%d %d", &a, &b);
	if(a<2) cout<<"Before";
	else if(a>2) cout<<"After";
	else
	{
		if(b<18) cout<<"Before";
		else if(b>18) cout<<"After";
		else cout<<"Special";
	}
	return 0;
}