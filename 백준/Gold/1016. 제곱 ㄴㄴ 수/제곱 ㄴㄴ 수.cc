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
	vector<bool> prime_check(1000005, false);
	prime_check[0] = prime_check[1] = true;
	lld mn, mx;
	cin>>mn>>mx;
	vector<bool> v(mx-mn+1, false);

	for(lld i=2;i<=1000000;i++)
	{
		if(prime_check[i]) continue;
		lld check_point = i*i;
		for(int j=i+i;j<=1000000;j+=i)
			prime_check[j] = true;
		lld start = (mn/check_point+1)*check_point;
		if(mn%check_point==0) start = mn;
		for(lld j=start;j<=mx;j+=check_point)
			v[mx-j] = true;
	}

	int cnt = 0;
	for(unsigned int i=0;i<v.size();i++)
		if(!v[i]) cnt++;
	cout<<cnt;
	return 0;
}