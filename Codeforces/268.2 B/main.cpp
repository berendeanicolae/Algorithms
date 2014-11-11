#include <cstdio>
#include <vector>
using namespace std;

int p, q, l, r, sol;
vector<pair<int, int>> x, z;

bool check(int t){
    int i, j;

    for (i=0, j=0; i<p && j<q;){
        if (x[i].first<=z[j].second+t && x[i].second>=z[j].first+t)
            return 1;
        if (x[i].first>z[j].second+t){
            ++j;
            continue;
        }
        if (x[i].second<z[j].first+t){
            ++i;
            continue;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d %d", &p, &q, &l, &r);
    x.resize(p);
    for (int i=0; i<p; ++i){
        scanf("%d %d", &x[i].first, &x[i].second);
    }
    z.resize(q);
    for (int i=0; i<q; ++i){
        scanf("%d %d", &z[i].first, &z[i].second);
    }
    for (int i=l; i<=r; ++i){
        sol += check(i);
    }
    printf("%d", sol);
    return 0;
}
