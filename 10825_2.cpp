#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

struct member
{
	char name[14];
	int k, e, m;
};

struct member stu[100000];

bool comp(struct member &a, struct member &b)
{
	if(a.k != b.k)
		return a.k > b.k;
	else
	{
		if(a.e != b.e)
			return a.e < b.e;
		else
		{
			if(a.m != b.m)
				return a.m > b.m;
			else
			{
				if(strcmp(a.name, b.name)<0)
					return true;
				return false;
			}
		}
	}
}
 
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf(" %s %d %d %d", stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m); 
	sort(stu, stu+n, comp);
	for(int i=0;i<n;i++)
		printf("%s\n",stu[i].name);
	return 0;
}