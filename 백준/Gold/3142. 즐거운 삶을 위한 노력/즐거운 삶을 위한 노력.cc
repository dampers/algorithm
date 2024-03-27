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


int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> primeCheck(1000001, 0);
	for(int i=2;i<=1000000;i++)
	{
		if(primeCheck[i]) continue;
		for(int j=i;j<=1000000;j+=i)
			primeCheck[j] = i;
	}
	
	
	vector<int> pcheck(1000001, 0);
	int flag = 0;
	while(n-- > 0)
	{
		int q;
		cin >> q;
		while(q > 1)
		{
            pcheck[primeCheck[q]] += 1;
            if(pcheck[primeCheck[q]] % 2) flag++;
            else flag--;
            q /= primeCheck[q];
		}
		if(!flag) cout << "DA\n";
		else cout << "NE\n";
	}

 	return 0;
}