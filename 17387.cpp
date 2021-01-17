#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
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
		cin>>cod[i].x>>cod[i].y;
	
	if(cod[0].x>cod[1].x) swap(cod[0], cod[1]);
	else if(cod[0].x==cod[1].x && cod[0].y>cod[1].y) swap(cod[0], cod[1]);
	if(cod[2].x>cod[3].x) swap(cod[2], cod[3]);
	else if(cod[2].x==cod[3].x && cod[2].y>cod[3].y) swap(cod[2], cod[3]);

	double r1 = 0.0, r2 = 0.0;
	bool flag1 = false, flag2 = false;
	if(cod[1].x != cod[0].x) r1 = (cod[1].y-cod[0].y)/(cod[1].x-cod[0].x);
	else flag1 = true;
	if(cod[3].x != cod[2].x) r2 = (cod[3].y-cod[2].y)/(cod[3].x-cod[2].x);
	else flag2 = true;

	double d1 = 0.0, d2 = 0.0;
	if(flag2 || flag1)
	{
		if(flag1 && flag2)
		{
			if(cod[0].x==cod[2].x)
			{
				if(cod[2].y<=cod[0].y && cod[0].y<=cod[3].y) cout<<1;
				else if(cod[2].y<=cod[1].y && cod[1].y<=cod[3].y) cout<<1;
				else if(cod[0].y<=cod[2].y && cod[2].y<=cod[1].y) cout<<1;
				else if(cod[0].y<=cod[2].y && cod[2].y<=cod[1].y) cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else if(flag1 && cod[2].x<=cod[0].x && cod[0].x<=cod[3].x)
		{
			d2 = cod[2].y-r2*cod[2].x;
			double ycod = r2*cod[0].x+d2;
			if(cod[0].y<=ycod && ycod<=cod[1].y) cout<<1;
			else cout<<0;
			//cout<<"\ny = "<<r2<<"x + "<<d2<<endl;
		}
		else if(flag2 && cod[0].x<=cod[2].x && cod[2].x<=cod[1].x)
		{
			d1 = cod[0].y-r1*cod[0].x;
			double ycod = r1*cod[2].x+d1;
			if(cod[2].y<=ycod && ycod<=cod[3].y) cout<<1;
			else cout<<0;
			//cout<<"\ny = "<<r1<<"x + "<<d1<<endl;
		}
		else cout<<0;

	}
	else
	{
		d1 = cod[0].y-r1*cod[0].x;
		d2 = cod[2].y-r2*cod[2].x;
		if(r1==r2)
		{
			if(d1==d2)
			{
				if(cod[2].x<=cod[0].x && cod[0].x<=cod[3].x) cout<<1;
				else if(cod[2].x<=cod[1].x && cod[1].x<=cod[3].x) cout<<1;
				else if(cod[0].x<=cod[2].x && cod[2].x<=cod[1].x) cout<<1;
				else if(cod[0].x<=cod[3].x && cod[3].x<=cod[1].x) cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else
		{
			double rk = r1-r2, dk = d1-d2, ans = -dk/rk;
			if(cod[0].x<=ans && ans<=cod[1].x && cod[2].x<=ans && ans<=cod[3].x)
				cout<<1;
			else cout<<0;
		}
	}
	return 0;
}