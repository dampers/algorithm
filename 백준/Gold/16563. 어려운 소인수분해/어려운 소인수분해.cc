#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int not_prime[5000005];

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    vi primes;
    for(int i=4;i<=5000000;i+=2) not_prime[i] = 2;
    primes.emplace_back(2);
    for(int i=3;i<=5000000;i+=2)
    {
        if(not_prime[i]) continue;
        primes.emplace_back(i);
        for(int j=i+i;j<=5000000;j+=i)
            if(!not_prime[j]) not_prime[j] = i;
    }
    
    int n;
    cin >> n;
    while(n-- > 0)
    {
        int k;
        cin >> k;
        while(not_prime[k])
        {
            cout << not_prime[k] << ' ';
            k = k / not_prime[k];
        }
        cout << k << endl;
    }
    
    
    

    return 0;
}