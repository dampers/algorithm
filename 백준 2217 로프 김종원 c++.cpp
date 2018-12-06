#include<bits/stdc++.h>

using namespace std;

int R[100001];

int main()
{
	int n,i,max=0,w;
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf(" %d", &R[i]);
	
	sort(R,R+n);
	
	for(i=0; i<n; i++)
	{
		w=(n-i)*R[i];
		if(w>max)	max=w;
	}

	printf("%d", max);
	
	return 0;
}
