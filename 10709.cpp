#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
	int h, w;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		int c = -1;
		char cl;
		for(int j=0;j<w;j++)
		{
			scanf(" %c", &cl);
			if(cl == 'c') c = 0;
			printf("%d ", c);
			if(c>=0) c++;
		}
		printf("\n");
	}
	return 0;
}