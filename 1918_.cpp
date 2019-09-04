#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[105];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf(" %s", s);
    vector<char> v;
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        int size = v.size();
        if(s[i]>='A' && s[i]<='Z') printf("%c", s[i]);
        else if(s[i]!=')')
        {
            if(s[i]=='-' || s[i]=='+')
            {
                for(int j=size-1;j>=0;j--)
                {
                    if(v[j]!='(')
                    {
                        printf("%c", v[j]);
                        v.pop_back();
                    }
                    else break;
                }
            }
            else if(s[i]=='*' || s[i]=='/')
            {
                for(int j=size-1;j>=0;j--)
                {
                    if(v[j]=='*' || v[j]=='/')
                    {
                        printf("%c", v[j]);
                        v.pop_back();
                    }
                    else break;
                }
            }
            v.push_back(s[i]);
        }
        else
        {
            for(int j=size-1;j>=0;j--)
            {
                if(v[j]=='(')
                {
                    v.pop_back();
                    break;
                }
                else
                {
                    printf("%c", v[j]);
                    v.pop_back();
                }
            }
        }
    }
    int size = v.size();
    for(int i=size-1;i>=0;i--)
    {
        printf("%c", v[i]);
        v.pop_back();
    }
    return 0;
}