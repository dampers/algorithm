#include <bits/stdc++.h>
 
using namespace std;
double h, v;
double a, b, c, d;

int main() {
	scanf("%lf %lf", &h, &v);
	a = sqrt(h*h+v*v);
	b = v*(h/(h+a));
	c = v*(a/(h+a));
	d = sqrt(b*b+h*h);
	
	printf("%.2lf ", d/2);
	printf("%.2lf", (c*h)/d);
	
	return 0;
}
