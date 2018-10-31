# include <stdio.h>

int main()
{
	int t, i, n;
	float d, a, b, f;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %f %f %f %f", &n, &d, &a, &b, &f);
		printf("%d %.2f\n", n, (d/(a+b))*f);
	}
}
