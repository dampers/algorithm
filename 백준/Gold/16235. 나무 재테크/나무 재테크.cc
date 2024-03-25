#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};


int N, M, K;
// priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> trees;
deque<pair<int, pii>> trees;
queue<pii> forFall;
int ground[11][11];
int addA[11][11];
int summerAdd[11][11];

void spring()
{
    int size = trees.size();
    while(size > 0)
    {
        size--;
        pair<int, pii> tree = trees.front();
        int currOld = tree.first;
        int currY = tree.second.first;
        int currX = tree.second.second;
        trees.pop_front();

        if(ground[currY][currX] >= currOld)
        {
            ground[currY][currX] -= currOld;
            currOld += 1;
            if(currOld % 5 == 0)
            {
                forFall.push({currY, currX});
            }
            tree.first = currOld;
            trees.push_back(tree);
        }
        else
        {
            // tree.first = LLONG_MAX;
            summerAdd[currY][currX] += currOld/2;
        }

    }
}

// void summer()
// {
//     sort(trees.begin(), trees.end());
//     while(trees.size() > 0)
//     {
//         if(trees.back().first == LLONG_MAX) trees.pop_back();
//         else break;
//     }
// }

void fall()
{
    while(!forFall.empty())
    {
        int y = forFall.front().first;
        int x = forFall.front().second;
        forFall.pop();

        for(int d=0;d<8;d++)
        {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny > N || nx > N || ny <= 0 || nx <= 0) continue;
            trees.push_front({1, {ny, nx}});
        }
    }
}

void winter()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ground[i][j] += addA[i][j] + summerAdd[i][j];
        }
    }
    memset(summerAdd, 0, sizeof(summerAdd));
}


void Input()
{
    cin >> N >> M >> K;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ground[i][j] = 5;
            cin >> addA[i][j];
        }
    }


    int x, y, z;
    for(int i=0;i<M;i++)
    {
        cin >> y >> x >> z;
        trees.push_back({z, {y, x}});
    }

}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();



    for(int year=0;year<K;year++)
    {
        spring();
        // summer();
        fall();
        winter();
    }

    cout << trees.size() << endl;



    return 0;
}