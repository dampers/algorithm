#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int n, h, w;
	scanf(" %d %d %d", &n, &w, &h);
	w *= w;
	h *= h;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf(" %d", &tmp);
		tmp *= tmp;
		if(w+h>=tmp) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}