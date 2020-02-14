#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int dp[1002], s;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	int cnt = 0;
	while(s>1)
	{
		if(s%2)
		{
			s++;
			cnt++;
		}
		cnt += 2;
		s /= 2;
	}
	cout<<cnt;
	return 0;
}