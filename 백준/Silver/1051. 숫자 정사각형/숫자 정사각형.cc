#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i];

    int ans = 1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            char curr = v[i][j];
            for(int l=1;i+l<N && j+l<M;l++)
                if(curr == v[i+l][j] && curr == v[i][j+l] && curr == v[i+l][j+l]) ans = max(ans, (l+1)*(l+1));
        }
    }

    cout << ans << endl;
    


    return 0;
}