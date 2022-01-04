#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
using nmp = map<pii, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


int getCost(int a, int b)
{
	if(a == 0) return 2;
	if(a == b) return 1;
	if(abs(a-b) == 2) return 4;
	return 3;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	vector<nmp> vmp;
	vmp.push_back(nmp());
	vmp[0][{0, 0}] = 0;
	int n;
	int vnum=0;
	for(;;vnum++)
	{
		cin >> n;
		if(n == 0) break;
		vmp.push_back(nmp());
		for(auto &P : vmp[vnum])
		{
			pii left = P.first, right = P.first;
			int lcost = P.second, rcost = P.second;
			lcost += getCost(left.first, n);
			left.first = n;
			rcost += getCost(right.second, n);
			right.second = n;
			if(left.first != left.second)
			{
				pii revleft = left;
				swap(revleft.first, revleft.second);
				auto lit = vmp[vnum+1].find(left);
				auto rlit = vmp[vnum+1].find(revleft);
				if(lit == vmp[vnum+1].end() && rlit == vmp[vnum+1].end())
				{
					vmp[vnum+1][left] = lcost;
				}
				else if(rlit == vmp[vnum+1].end())
				{
					vmp[vnum+1][left] = min((*lit).second, lcost);
				}
				else
				{
					vmp[vnum+1][revleft] = min((*rlit).second, lcost);
				}
			}
			
			if(right.first != right.second)
			{
				pii revright = right;
				swap(revright.first, revright.second);
				auto rit = vmp[vnum+1].find(right);
				auto rrit = vmp[vnum+1].find(revright);

				if(rit == vmp[vnum+1].end() && rrit == vmp[vnum+1].end())
				{
					vmp[vnum+1][right] = rcost;
				}
				else if(rrit == vmp[vnum+1].end())
				{
					vmp[vnum+1][right] = min((*rit).second, rcost);
				}
				else
				{
					vmp[vnum+1][revright] = min((*rrit).second, rcost);
				}
			}
		}
	}
	int ans = INT_MAX;

	for(auto &P : vmp[vnum])
		ans = min(ans, P.second);
	cout << ans;

	return 0;
}