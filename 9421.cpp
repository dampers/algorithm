#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<bool> prime(n+1, false);
	vector<int> prime_number;
	prime_number.push_back(2);
	for(int i=3;i<=n;i+=2)
	{
		if(prime[i]) continue;
		prime_number.push_back(i);
		for(int j=i+i;j<=n;j+=i)
			prime[j] = true;
	}
	set<int> st;
	st.insert(2);
	st.insert(4);
	int tmp = 16;
	while(tmp != 4)
	{
		st.insert(tmp);
		int stmp = tmp;
		tmp = 0;
		while(stmp>0)
		{
			tmp += (stmp%10)*(stmp%10);
			stmp /= 10; 
		}
	}
	int ans = 0;
	for(size_t i=0;i<prime_number.size();i++)
	{
		int stmp = prime_number[i];
		while(stmp != 1)
		{
			if(st.find(stmp) != st.end()) break;
			int atmp = stmp;
			stmp = 0;
			while(atmp>0)
			{
				stmp += (atmp%10) * (atmp%10);
				atmp /= 10;
			}
		}
		if(stmp == 1) cout<<prime_number[i]<<endl;
			//ans++;
	}
	//cout<<ans<<endl;
	return 0;
}