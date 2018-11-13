# include <bits/stdc++.h>

using namespace std;

char order[10];

int main()
{
	stack<int> stk;
	int t, i, j;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%s", order);
		if(strcmp(order, "push") == 0)
		{
			int k;
			scanf("%d", &k);
			stk.push(k);
		}
		else if(strcmp(order,"pop")==0)
		{
			if(stk.empty()) printf("-1\n");
			else
			{
				printf("%d\n", stk.top());
				stk.pop();
			}
		}
		else if(strcmp(order,"size")==0)
		{
			printf("%d\n", stk.size());
		}
		else if(strcmp(order,"empty")==0)
		{
			printf("%d\n", stk.empty());
		}
		else if(strcmp(order,"top")==0)
		{
			if(stk.empty()) printf("-1\n");
			else printf("%d\n", stk.top());
		}
		for(j=0;j<10;j++)
		{
			order[j] = '\0';
		}
	}
	return 0;
}
