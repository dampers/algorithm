#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	string mxname, mnname, tmp;
	int mxd, mxm, mxy, mnd, mnm, mny;
	mxd = mxm = mxy = 0;
	mnd = mnm = mny = 9999;
	int tmpd, tmpm, tmpy;
	for(int i=0;i<n;i++)
	{
		cin>>tmp>>tmpd>>tmpm>>tmpy;
		if(tmpy>mxy || (tmpy==mxy && tmpm>mxm) || (tmpy==mxy && tmpm==mxm && tmpd>mxd))
		{
			mnname = tmp;
			mxy = tmpy;
			mxm = tmpm;
			mxd = tmpd;
		}
		if(tmpy<mny || (tmpy==mny && tmpm<mnm) || (tmpy==mny && tmpm==mnm && tmpd<mnd))
		{
			mxname = tmp;
			mny = tmpy;
			mnm = tmpm;
			mnd = tmpd;
		}
	}
	cout<<mnname<<"\n"<<mxname<<endl;

	return 0;
}