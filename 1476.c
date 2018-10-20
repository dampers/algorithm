#include<stdio.h>

int main(void)
{
	int E, S, M;
	int e=1, s=1, m=1, y;
	
	scanf("%d %d %d", &E, &S, &M);
	
	for(y=1;;y++)
	{
		if (e == E && s == S && m == M)
			break;

		e++;
		s++;
		m++;

		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}

	printf("%d", y);
	return 0;
}
