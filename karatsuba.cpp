#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void addto(vector<int>& a, vector<int>& b, int k)
{
    a.resize(max(a.size()+2, b.size()+k+1), 0);
    int carry = 0;
    for(int i=0;i<b.size();i++)
    {
        a[i+k] += (b[i]+carry);
        carry = a[i+k]/10;
        a[i+k] %= 10;
    }
    while(a.size()>=1 && a.back()==0) a.pop_back();
}

void subfrom(vector<int>& a, vector<int>& b)
{
    int bor = 0;
    for(int i=0;i<a.size();i++)
    {
        if(i<b.size()) a[i] -= b[i]+bor;
        else
        {
            a[i] -= bor;
            if(!bor) break;
        }
        if(a[i]<0)
        {
            a[i] += 10;
            bor = 1;
        }
        else bor = 0;
    }
}

vector<int> multiple(vector<int>& a, vector<int>& b)
{
    // a.size() >= b.size()
    vector<int> res(a.size()+b.size()+2, 0);
    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            res[i+j] += a[j]*b[i];
        }
    }
    int carry = 0;
    for(int i=0;i<res.size();i++)
    {
        res[i] += carry;
        carry = res[i]/10;
        res[i] %= 10;
    }
    while(res.back()==0) res.pop_back();
    return res;
}


vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    int alen = a.size(), blen = b.size();
    if(alen<blen) return karatsuba(b, a);
    if(alen==0 || blen==0) return vector<int>();
    else if(alen<=230)
        return multiple(a, b);

    int half = alen/2;
    vector<int> a0(a.begin(), a.begin()+half), a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min((int)b.size(), half)), b1(b.begin()+min((int)b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1), z0 = karatsuba(a0, b0);
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
    vector<int> a(ai.length(), 0), b(bi.length(), 0);
    for(int i=0;i<ai.length();i++)
        a[i] = ai[ai.length()-i-1]-'0';
    for(int i=0;i<bi.length();i++)
        b[i] = bi[bi.length()-i-1]-'0';
    vector<int> ans = karatsuba(a, b);
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    cout<<endl;
    cout<<((double)clock()-start)/1000;
    return 0;
}