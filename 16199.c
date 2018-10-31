#include <stdio.h>
 
int main()
{
	int y1, m1, d1, y2, m2, d2, i, m, y;
	scanf("%d %d %d", &y1, &m1, &d1);
	scanf("%d %d %d", &y2, &m2, &d2);
	y = y2-y1;
	if(y1==y2) m = 0;
	if(y1<y2)
	{
		if(m1>m2) m = y2-y1-1;
		else if(m1<m2) m = y2-y1;
		else
		{
			if(d1>d2) m = y2-y1-1;
			else m = y2-y1;
		}
	}
	printf("%d\n%d\n%d", m, y+1, y);
    return 0;
}
