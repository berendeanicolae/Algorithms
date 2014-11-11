#include <cstdio>
#include <bitset>
#include <vector>
#define SIZE 10005
using namespace std;

int V, K, a, b;
vector<pair<int, int> > graph[SIZE];

void readGraph(){
    scanf("%d %d", &V, &K);
    for (int v=1; v<=V; ++v){
        graph[v].resize(0);
    }
    for (int k=0; k<K; ++k){
        int first, last, cost;

        scanf("%d %d %d", &first, &last, &cost);
        graph[first].push_back(make_pair(last, cost));
    }
    scanf("%d %d", &a, &b);
}

int solve(int a=1, int b=V){ //start, end
    unsigned cost[SIZE];
    bitset<SIZE> vis;

    for (int i=0; i<=V; ++i){
        cost[i] = 0xffffffff;
    }
    cost[a] = 0;
    while (!vis[b]){
        int pmin = 0;

        for (int i=1; i<=V; ++i){
            if (!vis[i] && cost[i]<cost[pmin])
                pmin = i;
        }
        if (pmin){
            int costpmin = cost[pmin];
            vis[pmin] = 1;
            for (unsigned i=0; i<graph[pmin].size(); ++i){
                if (cost[graph[pmin][i].first] > costpmin+graph[pmin][i].second){
                    cost[graph[pmin][i].first] = costpmin+graph[pmin][i].second;
                }
            }
            continue;
        }
        break;
    }
    return cost[b];
}

int main()
{
    int T;

    scanf("%d", &T);
    while (T--){
        int sol;
        readGraph();

        sol = solve(a, b);
        if (sol>=0){
            printf("%d\n", sol);
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
