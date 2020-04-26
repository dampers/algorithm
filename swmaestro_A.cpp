#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		//num[i] += num[i-1];
	}
	int l = 1, r = 2, cnt = 1;
	lld sum = num[1], mx = num[1];
	while(l<=r && l<=n && r<=n)
	{
		if(cnt>1 && sum-num[l]>sum)
		{
			l++;
			cnt--;
			sum -= num[l];
			continue;
		}
		else if(sum+num[r]<num[r])
		{
			sum = num[r];
			cnt = 1;
			l = r;
		}
		else
		{
			sum += num[r];
			cnt++;
		}
		r++;
		mx = max(mx, sum);
	}
	cout<<mx;
	return 0;
}