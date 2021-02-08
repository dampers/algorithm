#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int get_mn(int a1, int a2, int k1, int k2, int n)
{
	int amx = a1*(k1-1);
	int bmx = a2*(k2-1);
	if(amx+bmx >= n) return 0;
	return n-amx-bmx;
}

int get_mx(int a1, int a2, int k1, int k2, int n)
{
	int ans = 0;
	if(k1 < k2)
	{
		while(n-k1>=0 && a1>0)
		{
			ans++;
			n -= k1;
			a1--;
		}
		while(n-k2>=0 && a2>0)
		{
			ans++;
			n -= k2;
			a2--;
		}
	}
	else
	{
		while(n-k2>=0 && a2>0)
		{
			ans++;
			n -= k2;
			a2--;
		}
		while(n-k1>=0 && a1>0)
		{
			ans++;
			n -= k1;
			a1--;
		}
	}
	return ans;
	
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;
	int n;
	cin >> n;
	cout << get_mn(a1, a2, k1, k2, n) << ' ' << get_mx(a1, a2, k1, k2, n);
	return 0;
}