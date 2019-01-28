#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
	int a, b, c, d, p;
	cin>>a>>b>>c>>d>>p;
	int pa = p*a, pb;
	if(p<=c) pb = b;
	else pb = b+(p-c)*d;
	printf("%d", pa<pb?pa:pb);
	return 0;
}