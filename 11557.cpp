#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
typedef struct
{
	char name[21];
	int ac;
}univ;
univ coll[101];
int main()
{
	int t, n;
	scanf("%d", &t);
	int mx = 0, ind;
	for(int i=0;i<t;i++)
	{
		scanf("%d", &n);
		for(int j=0;j<n;j++)
		{
			scanf("%s %d\n", coll[j].name, &coll[j].ac);
			if(mx<coll[j].ac)
			{
				mx = coll[j].ac;
				ind = j;
			}
		}
		printf("%s\n", coll[ind].name);
	}

	return 0;
}