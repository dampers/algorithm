# include <bits/stdc++.h>

using namespace std;

int tree[1000001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf(" %d", &tree[i]);
	sort(tree, tree+n);
	for(int i=tree[n-2];i>0;i--)
	{
		int cut = 0;
		for(int j=n-1;j>=0;j--)
		{
			if((tree[j]-i)>0)
			{
				cut += (tree[j]-i);
			}
			if(cut>=m) break;
		}
		if(cut>=m)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}
