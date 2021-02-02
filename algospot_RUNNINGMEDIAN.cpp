#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct random_number_generator
{
	lld seed, a, b;
	random_number_generator()
	{
		seed = 1983;
		a = 0;
		b = 0;
	}
	random_number_generator(lld a, lld b)
	{
		seed = 1983;
		this->a = a;
		this->b = b;
	}
	lld next()
	{
		lld ret = seed;
		seed = (seed * a + b) % 20090711;
		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		lld a, b;
		cin>>n>>a>>b;
		random_number_generator rng(a, b);
		priority_queue<lld, vector<lld>, less<lld>> left;
		priority_queue<lld, vector<lld>, greater<lld>> right;
		lld ans = 0;
		while(n--)
		{
			if(left.size() == right.size()) left.push(rng.next());
			else right.push(rng.next());
			if(!left.empty() && !right.empty() && left.top() > right.top())
			{
				lld a = left.top(), b = right.top();
				left.pop();
				right.pop();
				left.push(b);
				right.push(a);
			}
			ans = (ans+left.top()) % 20090711;
		}
		cout<<ans<<endl;
	}

	return 0;
}