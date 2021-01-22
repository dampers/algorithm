#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		lld k, n;
		cin>>k>>n;

		lld last = 1983;
		int left = 0, right = 1, ans = 0;
		queue<lld> q;
		q.push(1984);
		lld sum = 1984;
		while(right<=n)
		{
			if(sum<k || left==right)
			{
				right++;
				last = (last*214013 + 2531011) % (1LL<<32);
				q.push((last%10000)+1);
				sum += (last%10000)+1;
			}
			else
			{
				if(sum==k) ans++;
				left++;
				sum -= q.front();
				q.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}