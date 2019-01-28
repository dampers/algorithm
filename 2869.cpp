#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	lld a, b, v;
	scanf(" %lld %lld %lld", &a, &b, &v);
	lld d, s = a-b;
	printf("%d",(v-b-1)/s+1);
	return 0;
}