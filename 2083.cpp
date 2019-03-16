#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char name[21];
int main()
{
	int age, wei;
	while(1)
	{
		scanf("%s %d %d", name, &age, &wei);
		if(age==0)
			break;
		printf("%s ", name);
		if(age>17||wei>=80)
			printf("Senior\n");
		else
			printf("Junior\n");
	}
	return 0;
}
