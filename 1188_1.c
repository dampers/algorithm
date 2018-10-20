#include<stdio.h>

int main()
{
	int N,M,i,T,sum=0;
	
	scanf("%d %d",&N,&M);
	
	T=N*M;
	
	for(i=0; i<M; i++)
	{
		T-=N;
		sum++;
		if(T%M==0)	sum--;
	}
	
	printf("%d", sum);
	
	return 0;
}
