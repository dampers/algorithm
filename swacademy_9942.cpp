#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

lld fac[15];
lld k;
int n, cnt;
bool check[11];

void f(int pos, lld sum)
{
	if(pos==n)
	{
		if(sum>=k) cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!check[i])
		{
			check[i] = true;
			f(pos+1, sum+max(i, pos+1));
			check[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fac[0] = fac[1] = 1LL;
	for(int i=2;i<11;i++)
		fac[i] = i*fac[i-1];

	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		cin>>n>>k;
		cout<<"#"<<t<<' ';
		cnt = 0;
		f(0, 0LL);
		cout<<cnt*fac[n]<<endl;


	}

	return 0;
}