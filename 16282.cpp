#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int main()
{
    lld n, ocnt = 0;
    scanf("%lld", &n);
    while(n)
    {
        if(ocnt*2+1>=n)
        {
            break;
        }
        n /= 2;
        ocnt++;
    }
    printf("%lld", ocnt);
    return 0;
}  