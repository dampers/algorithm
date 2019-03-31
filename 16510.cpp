#include <bits/stdc++.h>
using namespace std;

int task[10001];
int n, m;
int bsearch(int t, int task[])
{
	int left = 0;
	int right  = n-1;
	while(right-left>0)
	{
		int mid = (left+right)/2;
		if(task[mid]<t) left = mid +1;
		else right = mid;
		if(task[mid]==t)
			return mid+1;
	}
	return right;
}

int main()

{
	int tmp;
	scanf("%d %d", &n, &m);
	scanf(" %d", &task[0]);
	for(int i=1;i<n;i++)
	{
		scanf(" %d", &tmp);
		task[i] = task[i-1] + tmp;
	}
	int t, cnt = 0;
	for(int i=0;i<m;i++)
	{
		cnt = 0;
		scanf("%d", &t);
		if(t>=task[n-1])
			printf("%d\n", n);
		else
			printf("%d\n", bsearch(t, task));
	}
	return 0;
}