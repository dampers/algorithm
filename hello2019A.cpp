#include<bits/stdc++.h>
using namespace std;

struct card
{
	char s, r;
};
int main()
{
	struct card c[7];
	scanf(" %c%c", &c[0].r, &c[0].s);
	int flag = 0;
	for(int i=1;i<6;i++)
	{
		scanf(" %c%c", &c[i].r, &c[i].s);
		if(c[0].r==c[i].r || c[0].s==c[i].s)
		{
			flag = 1;
		}
	}
	if(flag) printf("YES");
	else printf("NO");
	return 0;
}
