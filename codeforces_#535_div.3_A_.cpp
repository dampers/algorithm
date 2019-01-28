#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x, y, r, t;
		cin>>x>>y>>r>>t;
		int a = x+1, b = r+1;
		if(a==b) a--;
		printf("%d %d\n",a,b);
	}
	return 0;
}