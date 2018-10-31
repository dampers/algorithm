#include <stdio.h>
 
int cycle(int a)
{
    int cnt=1;
    while(a>1)
    {
        if(a%2==0) a = a/2;
        else a = a*3+1;
    	cnt++;
    }
    return cnt;
     
}
int main() {
    int i, a, b, max = 0, tmp;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
    {
        tmp = cycle(i);
        if(max<tmp) max = tmp;
    }
    printf("%d",max);
    return 0;
}
