#include <stdio.h>
int main(){
	int i,n,sum;
	char num[100] = {0};
	sum = 0;
	scanf("%d",&n);
	scanf("%s",&num);
	for(i=0;i<n;i++)
	{
		sum += num[i]- '0';
		
	}
	printf("%d",sum);
  return 0;
}

