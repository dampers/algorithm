#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, num = 1, cnt = 0;
	scanf("%d", &n);
	while(1)
	{
		if(n<num) num = 1;
		n -= num;
		num++;
		cnt++;
		if(n==0) break;
	}
	printf("%d", cnt);
	return 0;
}
