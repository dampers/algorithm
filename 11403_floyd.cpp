#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dist[100][100]; // 절대 나올 수 없는 경로값
int main(){

    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
	{
        for(int j=0; j<N; j++)
		{
            scanf("%d", &dist[i][j]);

            if(dist[i][j] == 0) dist[i][j] = INF;

        }
    }
    
    for(int k=0; k<N; k++)

        for(int i=0; i<N; i++)

            for(int j=0; j<N; j++)

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i=0; i<N; i++){

        for(int j=0; j<N; j++)

            printf("%d ", dist[i][j]==INF ? 0 : 1);

        puts("");
        
    }
    return 0;
}