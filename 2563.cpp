#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
bool paper[102][102];
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int l, h;
		scanf(" %d %d", &l, &h);
		for(int j=l;j<l+10;j++)
			for(int k=h;k<h+10;k++)
				paper[j][k] = true;
	}
	int sum = 0;
	for(int i=0;i<102;i++)
		for(int j=0;j<102;j++)
			if(paper[i][j]==true) sum++;
	printf("%d", sum);
	return 0;
}