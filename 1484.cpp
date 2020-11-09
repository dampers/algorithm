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
	time_t start = clock();
	lld l = 1LL, r = 2LL, n;
	bool flag = false;
	cin>>n;
	while(l<r && r<=100000)
	{
		lld tmp = r*r-l*l;
		if(n==tmp)
		{
			flag = true;
			cout<<r<<endl;
			r++;
			l++;
		}
		else if(n>tmp) r++;
		else l++;
	}
	if(!flag) cout<<-1;
	return 0;
}