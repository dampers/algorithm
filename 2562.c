#include <stdio.h>
int main()
{
	int i,j,max,index;
	int a[9];
	max = 0;
	for(i=0;i<9;i++)
	{
		scanf("%d",&a[i]);
		if(max <= a[i])
		{
			max = a[i];
			index = i+1;
		}
	}
	printf("%d\n%d",max,index);

	return 0;	
}
