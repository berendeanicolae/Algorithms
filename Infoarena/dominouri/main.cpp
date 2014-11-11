#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 100005
using namespace std;

int N;
vector<int> graph[SIZE];
int F[SIZE];

void read(){
    freopen("dominouri.in", "r", stdin);
    freopen("dominouri.out", "w", stdout);

    scanf("%d", &N);
    for (int n=1; n<=N; ++n){
        int C;

        scanf("%d", &C);
        graph[n].resize(C);
        for (int c=0; c<C; ++c){
            scanf("%d", &graph[n][c]);
        }
    }
    for (int n=1; n<=N; ++n){
        scanf("%d", &F[n]);
    }
}

int solve(int node){
    int sol=0;

    if (F[node]==0){
        sol = 1;
    }
    else{
        vector<int> cost;
        cost.resize(graph[node].size());

        for (unsigned i=0; i<graph[node].size(); ++i){
            cost[i] = solve(graph[node][i]);
        }
        sort(cost.begin(), cost.end());
        for (int f=0; f<F[node]; ++f){
            sol += cost[f];
        }
    }

    return sol;
}

int main()
{
    read();
    printf("%d", solve(1));
    return 0;
}
