#include<stdio.h>

int main()
{
	int a, b, c; 
	scanf("%d %d %d", &a, &b, &c);

	if ((a <= 6 && a >= 1) && (b <= 6 && b >= 1) && (c <= 6 && c >= 1))
	{
		if ((a == b) && (b == c) && (c == a))
		{
			printf("%d", 10000 + (a * 1000));
		}
		else if (((a == b) && (a != c)) || ((a == c) && (a != b)) || ((c == b) && (a != c)))
		{
			if (a == b)
			{
				printf("%d", 1000 + (a * 100));
			}
			else if (b == c)
			{
				printf("%d", 1000 + (b * 100));
			}
			else if (c == a)
			{
				printf("%d", 1000 + (c * 100));
			}
			else
			{
				printf("");
			}
			
		}
		else if ((a != b) && (b != c) && (c != a))
		{
			if ((a > b) && (a > c))
			{
				printf("%d", a * 100);
			}
			else if ((b > c) && (b > a))
			{
				printf("%d", b * 100);
			}
			else if ((c > a) && (c > b))
			{
				printf("%d", c * 100);
			}
			else
			{
				printf("");
			}
		}
		else
		{
			printf("");
		}
	}
	else
	{
		printf("수가 맞지 않습니다.");
	}
	
	return 0;
}
