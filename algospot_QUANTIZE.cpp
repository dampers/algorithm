#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n;
lld a[101], p_sum[101], p_sq_sum[101];

void precalc()
{
	sort(a, a+n);
	p_sum[0] = a[0];
	p_sq_sum[0] = a[0]*a[0];
	for(int i=1;i<n;i++)
	{
		p_sum[i] = p_sum[i-1]+a[i];
		p_sq_sum[i] = p_sq_sum[i-1]+a[i]*a[i];
	}
}

lld minError(int lo, int hi)
{
	lld sum = p_sum[hi] - (lo==0?0:p_sum[lo-1]);
	lld sq_sum = p_sq_sum[hi] - (lo==0?0:p_sq_sum[lo-1]);
	lld m = lld(0.5 + (double)sum/(hi-lo+1));
	lld ret = sq_sum -2*m*sum + m*m*(hi-lo+1);
	return ret;
}

lld cache[101][11];

lld qantize(int from, int parts)
{
	if(from==n) return 0;
	if(parts == 0) return INT_MAX;
	lld& ret = cache[from][parts];
	if(ret!=-1) return ret;
	ret = INT_MAX;
	for(int part_size = 1;from+part_size<=n; part_size++)
	{
		ret = min(ret, minError(from, from+part_size-1)+qantize(from+part_size, parts-1));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int s;
		cin>>n>>s;
		for(int i=0;i<n;i++)
			cin>>a[i];
		memset(cache, -1, sizeof(cache));
		precalc();
		cout<<qantize(0, s)<<endl;
	}

	return 0;
}