#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char s[22], tmp[22];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf(" %s", s);
    int len = strlen(s);
    for(int i=0;i<len;i++)
        tmp[i] = s[i];
    reverse(s, s+len);
    if(!strcmp(s, tmp)) printf("true");
    else printf("false");
    return 0;
}