#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int T, n, m;
	vector<int> A, B;
	cin >> T;
	cin >> n;
	A.resize(n, 0);
	for(int i=0;i<n;i++)
		cin >> A[i];
	cin >> m;
	B.resize(m, 0);
	for(int i=0;i<m;i++)
		cin >> B[i];
	vector<int> pxA(n, 0), pxB(m, 0);
	pxA[0] = A[0];
	pxB[0] = B[0];
	for(int i=1;i<n;i++)
		pxA[i] = pxA[i-1] + A[i];
	for(int i=1;i<m;i++)
		pxB[i] = pxB[i-1] + B[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			pxA.push_back(pxA[j]-pxA[i]);
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			pxB.push_back(pxB[j]-pxB[i]);
	sort(pxA.begin(), pxA.end());
	sort(pxB.begin(), pxB.end());

	int ans = 0;
	for(int& pxak : pxA)
	{
		auto lit = lower_bound(pxB.begin(), pxB.end(), T-pxak);
		auto uit = upper_bound(pxB.begin(), pxB.end(), T-pxak);
		ans += (uit-lit);
	}
	cout << ans;

	return 0;
}