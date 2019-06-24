#include <iostream>
#include <cmath>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define PI 3.14159265358979
using namespace std;
typedef long long lld;
typedef struct
{
	double l;
	double r;
	double h;
}Res;
Res res[1001];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	setbuf(stdout, NULL);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		double rad, s, e;
		int n;
		cin>>rad>>s>>e>>n;
		double ans = e-s;
		for(int i=0;i<n;i++)
		{
			cin>>res[i].l>>res[i].r>>res[i].h;
			if(res[i].h>=rad)
			{
				ans -= 2*rad;
				ans += PI*rad+2*(res[i].h-rad);
			}
			else
			{
				ans -= 2*pow((rad*rad)-((rad-res[i].h)*(rad-res[i].h)), 0.5);
				ans += acos((rad-res[i].h)/rad)*rad*2;
			}
		}
		printf("Case #%d\n%.7lf\n", z, ans);
	}
	return 0;
}