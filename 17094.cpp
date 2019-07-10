#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	int tcnt = 0, ecnt = 0;
	for(int i=0;i<n;i++)
	{
		char tmp;
		scanf(" %c", &tmp);
		if(tmp=='2')
			tcnt++;
		else if(tmp=='e')
			ecnt++;
	}
	if(tcnt>ecnt)
		printf("2");
	else if(tcnt<ecnt)
		printf("e");
	else
		printf("yee");
	return 0;
}