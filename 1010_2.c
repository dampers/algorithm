# include <stdio.h>

int cmb(int n, int m)
{
	if(m==0 || m==n) return 1;
	else return cmb(n-1, m-1) + cmb(n-1, m);
}

int main()
{
	int t, i, n, m, c;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &n, &m);
		c = cmb(m, n);
		printf("%d\n", c);
	}
	return 0;
}
