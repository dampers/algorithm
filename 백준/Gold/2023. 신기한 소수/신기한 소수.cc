#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N;

bool is_prime(int value)
{
    int sqrt_v = sqrt(value);
    for(int i=2;i<=sqrt_v;i++)
        if (value % i == 0) return false;
    return true;
}

void recur(int pos, int value)
{
    if(pos == N)
    {
        cout << value << endl;
        return;
    }
    for(int i=1;i<10;i++)
    {
        int next = value * 10 + i;
        if(is_prime(next)) recur(pos+1, next);
    }
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> primes = {2, 3, 5, 7};
    if(N == 1)
    {
        for(size_t i=0;i<primes.size();i++)
            cout << primes[i] << endl;
        return 0;
    }

    for(size_t i=0;i<primes.size();i++)
        recur(1, primes[i]);



    return 0;
}