#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
bool prime[1000001];
int main()
{				//if prime[i] == true : 'i' is not prime number.
				//if == false : 'i' is prime number.
	prime[1] = true;
	for(int i=2;i*i<1000001;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<1000001;j+=i)
			prime[j] = true;
	}
	return 0;
}
