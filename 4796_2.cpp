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
	int l, p, v;
	int tc = 1;
	while(1)
	{
		cin>>l>>p>>v;
		if(l==0 && p==0 && v==0) break;
		lld ans = (lld)(v/p)*l;
		if(v%p<l) ans += v%p;
		else ans += l;
		cout<<"Case "<<tc<<": "<<ans<<endl;
		tc++;
		
	}
	return 0;
}