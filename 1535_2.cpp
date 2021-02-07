#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;


int n, mx;

void get_mx(int num, int hp, int joy,
	vector<int>& loss, vector<int>& joys, vector<bool>& check)
{
	if(hp <= 0) return;
	mx = max(mx, joy);
	for(int i=num;i<n;i++)
	{
		if(!check[i])
		{
			check[i] = true;
			joy += joys[i];
			hp -= loss[i];
			get_mx(i, hp, joy, loss, joys, check);
			joy -= joys[i];
			hp += loss[i];
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	vector<int> loss(n, 0), joys(n, 0);
	vector<bool> check(n, false);
	for(int i=0;i<n;i++)
		cin >> loss[i];
	for(int i=0;i<n;i++)
		cin >> joys[i];
	get_mx(0, 100, 0, loss, joys, check);
	cout<<mx;

	return 0;
}