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
	int w, h;
	cin>>w>>h;
	int mx = max(w, h), mn = min(w, h);
	if(mn==1 || mn == 2)
	{
		cout<<mn*mx;
		return 0;
	}
	int scnt = mn%3, cnt = 0, kcnt = 0;
	mn -= (mn%3);
	kcnt = mx/mn;
	cnt += kcnt;
	cnt += scnt*mx;
	mx -= mx%3;
	cnt += scnt*mx;
	//cout<<mn<<' '<<mx<<endl;
	cout<<cnt;
	return 0;
}