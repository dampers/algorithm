# include <stdio.h>
# include <math.h>

int main()
{
	int t, i, cap, time, tmp, j, ttmp;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &cap, &time);
		tmp = cap/pow(2,time/10);
		if(tmp==0) printf("Can not\n\n");
		else printf("%d\n\n", tmp);
	}
	return 0;
}
