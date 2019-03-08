#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int h1, m1, h2, m2, t1, t2, pt;
	scanf("%2d:%2d\n%2d:%2d", &h1, &m1, &h2, &m2);
	t1 = h1*60+m1;
	t2 = h2*60+m2;
	if(t1<t2)
	{
		pt = t1+(t2-t1)/2;
	}
	else if(t1>t2)
	{
		pt = t1+(24*60 - t1 + t2)/2;
		if(pt>=24*60)
			pt -= 24*60;
	}
	int ph, pm;
	ph = pt/60;
	pm = pt%60;
	if(ph<10&&pm<10)
		printf("0%d:0%d", ph, pm);
	else if(ph<10)
		printf("0%d:%d", ph, pm);
	else if(pm<10)
		printf("%d:0%d", ph, pm);
	else
		printf("%d:%d", ph, pm);
	return 0;
}