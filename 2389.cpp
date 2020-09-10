#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

double dst(double x, double y)
{
	return x*x+y*y;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	vector<pair<double, double>> v;
	double cx = 0.0, cy = 0.0;
	for(int i=0;i<n;i++)
	{
		double x, y;
		cin>>x>>y;
		v.push_back({x, y});
		cx += x;
		cy += y;
	}

	cx /= n;
	cy /= n;

	double r = 0.1, mx = 0.0;
	for(int i=0;i<10000;i++)
	{
		int ind = 0;
		mx = 0.0;
		for(int j=0;j<n;j++)
		{
			double d = dst(cx-v[j].first, cy-v[j].second);
			if(mx<d)
			{
				ind = j;
				mx = d;
			}
		}
		cx += (v[ind].first-cx)*r;
		cy += (v[ind].second-cy)*r;
		r *= 0.999;
	}
	cout<<cx<<' '<<cy<<' '<<sqrt(mx);
	return 0;
}