#include <bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<int> pq;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf(" %d", &t);
		pq.push(-t);
	}
	for(int i=0;i<n;i++){
		printf("%d\n", -pq.top());
		pq.pop();
	}
	return 0;
}