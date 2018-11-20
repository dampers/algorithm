# include <stdio.h>

float cir(float n, float h)
{
	return n*2+h*2;
}
float area(float n, float h)
{
	return n*h;
}

int main()
{
	float n, h;
	scanf("%f %f", &n, &h);
	printf("Circumference:%.3f\nArea:%.3f", cir(n, h), area(n, h));
	return 0;
}
