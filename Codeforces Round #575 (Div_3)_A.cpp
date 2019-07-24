#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		lld a, b, c;
		cin>>a>>b>>c;
		cout<<(a+b+c)/2<<'\n'; 
	}
	return 0;
}