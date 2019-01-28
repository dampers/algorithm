#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if(w/2<x) x = w-x;
	if(h/2<y) y = h-y;
	printf("%d", x>y?y:x);
	return 0;
}