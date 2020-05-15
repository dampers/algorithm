#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct Custom
{
	int l;
	int r;
	int val;
	Custom(int l, int r, int val):l(l),r(r),val(val){}
};

struct comp
{
	bool operator()(Custom t, Custom u)
	{
		if(t.val==u.val) return t.l>u.l;
		return t.val<u.val;
	}
};

int num[200005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n==2)
		{
			cout<<1<<' '<<2<<endl;
			continue;
		}
		memset(num, 0, sizeof(num));
		priority_queue<Custom, vector<Custom>, comp>pq;
		pq.push(Custom(1, n, n));
		int sk = 1;
		while(!pq.empty())
		{
			Custom a = pq.top();
			pq.pop();
			int l = a.l, r = a.r, len = a.val;
			if(l>r) continue;
			int mid = (r-l+1)%2?(r+l)/2:(l+r-1)/2;
			if(num[mid]!=0) continue;
			num[mid] = sk++;
			if(sk>n) break;
			pq.push(Custom(l, mid-1, (mid-l)));
			pq.push(Custom(mid+1, r, (r-mid)));
		}
		for(int i=1;i<=n;i++)
			cout<<num[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}