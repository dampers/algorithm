#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	string king, rock;
	int n;
	cin >> king >> rock >> n;
	string order;
	int ky = king[1]-'1', kx = king[0]-'A';
	int ry = rock[1]-'1', rx = rock[0]-'A';
	for(int i=0;i<n;i++)
	{
		cin >> order;
		int ny = 0, nx = 0;
		for(auto &A : order)
		{
			if(A == 'R') nx++;
			else if(A == 'L') nx--;
			else if(A == 'B') ny--;
			else if(A == 'T') ny++;
		}
		int kny = ky+ny, knx = kx+nx;
		int rny = ry+ny, rnx = rx+nx;
		if(kny >= 8 || knx >= 8 || kny < 0 || knx < 0) continue;
		if(kny == ry && knx == rx)
		{
			if(rny >= 8 || rnx >= 8 || rny < 0 || rnx < 0) continue;
			ry = rny;
			rx = rnx;
		}
		ky = kny;
		kx = knx;
	}
	cout << (char)(kx+'A') << ky+1 << endl;
	cout << (char)(rx+'A') << ry+1 << endl;
	return 0;
}