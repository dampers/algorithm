#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main(){
	int n, r, e, c, i;
	scanf(" %d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d", &r, &e, &c);
		if(r>e-c)
		{
			printf("do not advertise\n");
		}
		else if(r==e-c)
		{
			printf("does not matter\n");
		}
		else if(r<e-c)
		{
			printf("advertise\n");
		}
	}
	return 0;
}