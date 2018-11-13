# include <bits/stdc++.h>

using namespace std;

char order[15];

int main()
{
	int t, i, j;
	queue<int> q;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%s", order);
		if(strcmp(order, "push") == 0)
		{
			int k;
			scanf("%d", &k);
			q.push(k);
		}
		else if(strcmp(order,"pop")==0)
		{
			if(q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if(strcmp(order,"size")==0)
		{
			printf("%d\n", q.size());
		}
		else if(strcmp(order,"empty")==0)
		{
			printf("%d\n", q.empty());
		}
		else if(strcmp(order,"front")==0)
		{
			if(q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if(strcmp(order,"back")==0)
		{
			if(q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
		for(j=0;j<strlen(order);j++) order[j] = '\0';
	}
	return 0;
}
