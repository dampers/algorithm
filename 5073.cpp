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
	int a, b, c;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0) return 0;
		int mx = max(a, max(b, c));
		if(mx==a && b+c<=a) cout<<"Invalid\n";
		else if(mx==b && a+c<=b) cout<<"Invalid\n";
		else if(mx==c && a+b<=c) cout<<"Invalid\n";
		else if(a==b && b==c) cout<<"Equilateral\n";
		else if(a==b || b==c || a==c) cout<<"Isosceles\n";
		else cout<<"Scalene\n";
	}
	
	return 0;
}