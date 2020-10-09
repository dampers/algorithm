#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

lld mn = LLONG_MAX;
lld n;
int m;

void f(int pos, lld res, vector<bool>& check)
{
	if(pos==8) return;
	for(int i=0;i<10;i++)
	{
		if(!check[i])
		{
			res += i;
			mn = min(abs(res-n)+pos+1, mn);
			f(pos+1, res*10, check);
			res -= i;
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	time_t start = clock();
	cin>>n>>m;
	vector<int> v(m);
	vector<bool> check(10, false);
	mn = abs(100LL-n);
	for(int i=0;i<m;i++)
	{
		cin>>v[i];
		check[v[i]] = true;
	}
	f(0, 0LL, check);
	cout<<mn;

	return 0;
}