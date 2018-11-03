# include <stdio.h>

int mt[4];

int main()
{
	int i, m1, m2, m3, m4, m5;
	scanf("%d %d", &m1, &m2);
	for(i=0;i<3;i++)
	{
		mt[i] = m2%10;
		m2 /= 10;
	}
	m3 = mt[0] * m1;
	m4 = mt[1] * m1;
	m5 = mt[2] * m1;
	printf("%d\n%d\n%d\n%d",m3, m4, m5, m3+10*m4+100*m5);
	return 0;
}
