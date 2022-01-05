#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int a, b;
	cin >> a >> b;
	a--;
	vector<int> ps, ones;
	ones.push_back(0);
	int uppers = 1, ucnt = 1, osums = 0;
	for(int i=b*4;i>0;i >>= 1)
	{
		ps.push_back(uppers);
		ucnt++;
		ones.push_back(osums+uppers);
		osums += ones.back();
		uppers <<= 1;
	}
	reverse(ps.begin(), ps.end());
	vector<int> pxones(ones.size(), 0);
	for(size_t i=1;i<ones.size();i++)
		pxones[i] = pxones[i-1] + ones[i];
	reverse(pxones.begin(), pxones.end());

	int acnt = 0, bcnt = 0, aocnt = 0, bocnt = 0;
	for(size_t i=0;i<ps.size();i++)
	{
		if(a&ps[i])
		{
			acnt += pxones[i+1] + ps[i] * aocnt + 1;
			aocnt++;
		}
		if(b&ps[i])
		{
			bcnt += pxones[i+1] + ps[i] * bocnt + 1;
			bocnt++;
		}
	}
	cout << bcnt-acnt << endl;
	return 0;
}