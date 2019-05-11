#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int av, bv, a;
		scanf("%d %d %d", &av, &bv, &a);
		int cnt = 0;
		if(bv<=av)
		{
			printf("0\n");
			continue;
		}
		for(int j=a;;j+=a)
		{
			av+=j;
			cnt++;
			//printf("av = %d bv = %d\n", av ,bv);
			if(bv<=av)
			{
				printf("%d\n", cnt);
				break;
			}
		}
	}
	return 0;
}