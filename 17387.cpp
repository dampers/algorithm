#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lld;

void swap(pair<double, double>& a, pair<double, double>& b)
{
	pair<double, double> tmp;
	tmp = a;
	a = b;
	b = tmp;
}




int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<pair<double, double>> cod(4);
	for(int i=0;i<4;i++)
		cin>>cod[i].first>>cod[i].second;
	
	if(cod[0].first>cod[1].first) swap(cod[0], cod[1]);
	else if(cod[0].first==cod[1].first && cod[0].second>cod[1].second) swap(cod[0], cod[1]);
	if(cod[2].first>cod[3].first) swap(cod[2], cod[3]);
	else if(cod[2].first==cod[3].first && cod[2].second>cod[3].second) swap(cod[2], cod[3]);

	double r1 = 0.0, r2 = 0.0;
	bool flag1 = false, flag2 = false;
	if(cod[1].first != cod[0].first) r1 = (cod[1].second-cod[0].second)/(cod[1].first-cod[0].first);
	else flag1 = true;
	if(cod[3].first != cod[2].first) r2 = (cod[3].second-cod[2].second)/(cod[3].first-cod[2].first);
	else flag2 = true;

	double d1 = 0.0, d2 = 0.0;
	if(flag2 || flag1)
	{
		if(flag1 && flag2)
		{
			if(cod[0].first==cod[2].first)
			{
				if(cod[0].second<=cod[2].second && cod[2].second<=cod[1].second) cout<<1;
				else if(cod[0].second>=cod[2].second && cod[0].second<=cod[3].second) cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else if(flag1 && cod[0].first>=cod[2].first && cod[0].first<=cod[3].first)
		{
			d2 = cod[2].second-r2*cod[2].first;
			double y = r2*cod[0].first+d2;
			if(y>=cod[0].second && y<=cod[1].second) cout<<1;
			else cout<<0;
			//cout<<"\ny = "<<r2<<"x + "<<d2<<endl;
		}
		else if(flag2 && cod[2].first>=cod[0].first && cod[2].first<=cod[1].first)
		{
			d1 = cod[0].second-r1*cod[0].first;
			double y = r1*cod[2].first+d1;
			if(y>=cod[2].second && y<=cod[3].second) cout<<1;
			else cout<<0;
			//cout<<"\ny = "<<r1<<"x + "<<d1<<endl;
		}
		else cout<<0;

	}
	else
	{
		d1 = cod[0].second-r1*cod[0].first;
		d2 = cod[2].second-r2*cod[2].first;
		if(r1==r2)
		{
			if(d1==d2)
			{
				if(cod[0].first<=cod[2].first && cod[1].first>=cod[2].first) cout<<1;
				else if(cod[0].first>=cod[2].first && cod[0].first<=cod[3].first) cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else
		{
			double rk = r1-r2, dk = d2-d1, ans = dk/rk;
			if(ans>=cod[0].first && ans<=cod[1].first) cout<<1;
			else cout<<0;
		}
		//cout<<"\ny = "<<r1<<"x + "<<d1<<endl;
		//cout<<"\ny = "<<r2<<"x + "<<d2<<endl;
	}
	return 0;
}