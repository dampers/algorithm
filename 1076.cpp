#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

string color[] = {{"black"}, {"brown"}, {"red"}, {"orange"}, {"yellow"}, {"green"}, {"blue"}, {"violet"}, {"grey"}, {"white"}};
char buf[10];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld tmp = 0;
	lld ans = 0;
	for(int i=0;i<3;i++)
	{
		tmp = 0;
		scanf(" %s", &buf);
		for(int j=0;j<10;j++)
		{
			if(buf==color[j])
			{
				tmp = j;
				break;
			}
		}
		if(i==2) ans *= pow(10, tmp);
		else if(i==1) ans += tmp;
		else if(i==0) ans += tmp*10;
	}
	printf("%lld", ans);
	return 0;
}