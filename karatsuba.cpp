#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void addto(vector<int>& a, vector<int>& b, int k)
{
    while(a.size()<b.size()+k) a.push_back(0);
    int carry = 0;
    for(int i=0;i<b.size();i++)
    {
        a[i+k] += (b[i]+carry);
        carry = a[i+k]/10;
        a[i+k] %= 10;
    }
    if(carry!=0) a.push_back(1);
    while(*(a.end()-1)==0) a.pop_back();
}

void subfrom(vector<int>& a, vector<int>& b)
{
    int bor = 0;
    for(int i=0;i<a.size();i++)
    {
        if(i<b.size()) a[i] -= b[i]+bor;
        else a[i] -= bor;
        if(a[i]<0)
        {
            a[i] += 10;
            bor = 1;
        }
        else bor = 0;
    }
}


vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    int alen = a.size(), blen = b.size();
    if(alen<blen) return karatsuba(b, a);
    if(alen==0 || blen==0) return vector<int>();
    else if(alen==1 && blen==1)
    {
        int tmp = a[0]*b[0];
        vector<int> tmpv;
        tmpv.push_back(tmp%10);
        if(tmp>9) tmpv.push_back(tmp/10);
        return tmpv;
    }

    int half = alen/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min((int)b.size(), half));
    vector<int> b1(b.begin()+min((int)b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addto(a0, a1, 0);
    addto(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subfrom(z1, z0);
    subfrom(z1, z2);

    vector<int> ret;
    addto(ret, z0, 0);
    addto(ret, z1, half);
    addto(ret, z2, half+half);
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    time_t start = clock();
    string ai, bi;
    cin>>ai>>bi;
    vector<int> a(ai.length()), b(bi.length());
    for(int i=0;i<ai.length();i++)
        a[i] = ai[i]-'0';
    for(int i=0;i<bi.length();i++)
        b[i] = bi[i]-'0';
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans = karatsuba(a, b);
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}