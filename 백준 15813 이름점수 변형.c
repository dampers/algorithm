#include <stdio.h>

int i,n, sum=0;
char name[109];

int main() {
	scanf("%d", &n);
	scanf("%s", &name);	
	for(i = 0; i<n; i++)
	{
		sum+=name[i]-64;
	}
	
	printf("%d", sum);
	
	return 0;
}
