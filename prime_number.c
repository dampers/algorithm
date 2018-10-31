#include <stdio.h>
 
int so(int n)
{
    int i;
    if(n==2) return 2;
    for(i=2;i<n;i++) if(n%i==0) return 0;
    return n;
}
int main() {
    int t, i, tmp, cnt, j, k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        cnt=0;
        scanf("%d",&tmp);
        for(j=2;j<=tmp;j++)
        {
            k = so(j);
            if(k==0) continue;
            printf("%d ",k);
            cnt++;
            if(cnt==10)
            {
                printf("\n");
                cnt=0;
            }
        }
        printf("\n\n");
    }
    return 0;
}
