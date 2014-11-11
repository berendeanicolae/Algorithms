#include <cstdio>
#include <vector>
#include <bitset>
#define SIZE 1000005
using namespace std;

int N, M, P;
vector<int> graph[SIZE];
bitset<SIZE> vis;

int main()
{
    freopen("berarii2.in", "r", stdin);
    freopen("berarii2.out", "w", stdout);

    scanf("%d %d %d", &N, &M, &P);

    for (int m=0; m<M; ++m){
        int X, Y;

        scanf("%d %d", &X, &Y);
        graph[Y].push_back(X);
    }


    int src;
    vector<int> que;
    for (int p=0; p<P; ++p){
        int src;

        scanf("%d", &src);
        vis[src] = 1;
        que.push_back(src);
    }
    for (unsigned i=0; i<que.size(); ++i){
        src = que[i];

        for (unsigned j=0; j<graph[src].size(); ++j){
            if (!vis[graph[src][j]]){
                vis[graph[src][j]] = 1;
                que.push_back(graph[src][j]);
            }
        }
    }

    printf("%d\n", N-vis.count());
    for (int n=1; n<=N; ++n){
        if (!vis[n])
            printf("%d\n", n);
    }
    return 0;
}
