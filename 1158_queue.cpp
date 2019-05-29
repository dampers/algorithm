#include <bits/stdc++.h>
using namespace std;

int main()
{
	queue <int> q;
	int n ,m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		q.push(i);
	int size = q.size();
	printf("<");
	while(1)
	{
		if(size==1)
		{
			printf("%d>", q.front());
			break;
		}
		for(int i=1;i<m;i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
		size = q.size();
	}
	return 0;
}