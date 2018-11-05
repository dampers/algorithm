# include <stdio.h>

int a[11], b[11];

int main()
{
	int i, an = 0, bn = 0;
	for(i=0;i<10;i++) scanf("%d", &a[i]);
	for(i=0;i<10;i++) scanf("%d", &b[i]);
	for(i=0;i<10;i++)
	{
		if(a[i]>b[i]) an++;
		else if(a[i]<b[i]) bn++;
	}
	if(an>bn) printf("A");
	else if(an<bn) printf("B");
	else printf("D");
	return 0;
}
