#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int atmp, btmp, awin = 0, bwin = 0;
	for(int i=0;i<n;i++)
	{
		cin>>atmp>>btmp;
		if(atmp>btmp) awin++;
		else if(atmp<btmp) bwin++;
	}
	printf("%d %d", awin, bwin);
	return 0;
}