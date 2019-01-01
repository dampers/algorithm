#include<bits/stdc++.h>

using namespace std;

int tri[4];

int main()
{
	int t;
	scanf(" %d", &t);
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf(" %d", &tri[j]);
		}
		sort(tri, tri+3);
		printf("Case #%d: ", i);
		if(tri[0]==tri[1] && tri[1]==tri[2]) printf("equilateral\n");
		else if(tri[2]<tri[1]+tri[0])
		{
			if(tri[2]==tri[1] || tri[1]==tri[0]) printf("isosceles\n");
			else printf("scalene\n");
		}
		else printf("invalid!\n");
	}
	return 0;
}
