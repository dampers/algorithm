#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, o, x;
	scanf("%d %d %d", &n, &m, &k);
	printf("%d",(m<k?m:k)+n-(m>k?m:k));
	return 0;
}
