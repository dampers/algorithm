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
	vector<lld> prime_number;

	for(lld i=2;i<=1000000;i++)
	{
		if(prime_check[i]) continue;
		prime_number.push_back(i*i);
		for(int j=i+i;j<=1000000;j+=i)
			prime_check[j] = true;
	}

	for(size_t i=0;i<prime_number.size();i++)
	{
		lld check_point = (mn / prime_number[i]+1) * prime_number[i];
		if(mn % prime_number[i]==0) check_point = mn;
		for(lld j=check_point;j<=mx;j+=prime_number[i])
			v[mx-j] = true;
	}

	int cnt = 0;
	for(size_t i=0;i<v.size();i++)
		if(!v[i]) cnt++;
	cout<<cnt;
	return 0;
}