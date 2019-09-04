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
	lld l, p, v;
	for(int i=1;;i++)
	{
		cin>>l>>p>>v;
		if(!l && !p && !v) return 0;
		cout<<"Case "<<i<<": ";
		lld sum = (v/p)*l;
		if(v%p<l) sum += v%p;
		else sum += l;
		cout<<sum<<endl;
	}
	return 0;
}