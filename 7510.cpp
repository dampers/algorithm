#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[4];
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<3;j++)
			scanf(" %d", &num[j]);
		sort(num, num+3);
		int tmp = pow(num[0],2)+pow(num[1],2);
		printf("Scenario #%d:\n", i+1);
		if(tmp==pow(num[2],2))
			printf("yes\n\n");
		else
			printf("no\n\n");
	}
	return 0;
}