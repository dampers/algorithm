#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circle
{
	int r;

};
int main()
{
	struct circle a;
	scanf("%d", &a.r);
	printf("%.3f %.3f", a.r*3.141592*2, a.r*a.r*3.141592);
	return 0;
}