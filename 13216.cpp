#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
	char tmp;
	int spa = 0, spb = 0;
	int pa = 0, pb = 0;
	while(spa<2&&spb<2)
	{
		scanf("%c", &tmp);
		if(tmp == 'A')
			pa++;
		else
			pb++;
		if(pa==21)
		{
			spa++;
			printf("%d-%d\n", pa, pb);
			pa = 0;
			pb = 0;
		}
		else if(pb==21)
		{
			spb++;
			printf("%d-%d\n", pa, pb);
			pa = 0;
			pb = 0;
		}
	}
	if(spa==2)
		printf("A");
	else
		printf("B");
	return 0;
}