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
    vector<vector<double>> matrix(n+1, vector<double>(n+1, 0.0));
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            cin >> matrix[i][j];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
            matrix[i][j] /= matrix[i][i];
        matrix[i][i] = 1.0;
        for(int j=i+1;j<n;j++)
        {
            double kp = matrix[j][i];
            vector<double> mkmatrix = matrix[i];
            for(int k=0;k<=n;k++)
                matrix[j][k] -= (mkmatrix[k] * kp);
        }
    }

    vector<double> ans(n, 0.0);
    ans[n-1] = matrix[n-1][n];
    for(int i=n-2;i>=0;i--)
    {
        ans[i] = matrix[i][n];
        for(int j=n-1;j>i;j--)
            ans[i] -= matrix[i][j] * ans[j];
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';
    return 0;
}