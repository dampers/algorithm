#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main(){
	int n, r, c, cnt=0;
	scanf("%d %d %d", &n, &r, &c);
	int range = pow(2, n);
	int fm = 0;
	int hrange = pow(2, n-1);
	int halfx = range/2, halfy = range/2;
	for(int i=0;i<n;i++,range /= 2, hrange /= 2)
	{
		int flagx = 0, flagy = 0;
		//printf("range = %d\n", range);
		//printf("halfx = %d halfy = %d\n", halfx, halfy);
		flagx = c<halfx?0:1;
		flagy = r<halfy?0:1;
		if(flagx) halfx += hrange/2;
		else halfx -= hrange/2;
		if(flagy) halfy += hrange/2;
		else halfy -= hrange/2;
		//printf("%d%d\n", flagy, flagx);
		fm = flagx*1+flagy*2;
		cnt += pow(range, 2)/4*fm;
		//printf("fm = %d ", fm);
		//printf("cnt = %d\n", cnt);
	}
	printf("%d", cnt);
	return 0;
}