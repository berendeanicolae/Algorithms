#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#define SIZE 10001
using namespace std;

int n, m, s, d;
vector<int> graph[SIZE], dgraph[SIZE];

void read()
{
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i){
        scanf("%d %d", &s, &d);
        graph[s].push_back(d);
        dgraph[d].push_back(s);
    }
    scanf("%d %d", &s, &d);
}

unsigned solve(vector<int> graph[SIZE], vector<int> dgraph[SIZE]){
    if (s==d){
        return 0;
    }


    bitset<SIZE> vis;
    vector<int> que;
    int sol = 0;

    que.push_back(s);
    vis[s] = 1;
    while (!vis[d]){
        if (!que.size()){
            return 0xffffffff;
        }


        vector<int> tque;
        for (unsigned i=0; i<que.size(); ++i){
            int node = que[i];
            if (sol%2){
                for (unsigned j=0; j<dgraph[node].size(); ++j){
                    if (!vis[dgraph[node][j]]){
                        vis[dgraph[node][j]] = 1;
                        que.push_back(dgraph[node][j]);
                        tque.push_back(dgraph[node][j]);
                    }
                }
            }
            else{
                for (unsigned j=0; j<graph[node].size(); ++j){
                    if (!vis[graph[node][j]]){
                        vis[graph[node][j]] = 1;
                        que.push_back(graph[node][j]);
                        tque.push_back(graph[node][j]);
                    }
                }
            }
        }
        que.swap(tque);
        ++sol;
    }

    return sol-1;
}

int main()
{
    read();
    printf("%d", min(solve(graph, dgraph), solve(dgraph, graph)));
    return 0;
}
