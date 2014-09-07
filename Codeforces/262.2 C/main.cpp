#include <cstdio>
#include <vector>
using namespace std;

int n, m, w, vmin=1000000000;
vector<int> v;

bool isSol(int sol){
    vector<int> ends;
    int m_cpy=m, h=0;

    ends.resize(n);
    for (int i=0; i<v.size(); ++i){
        if (i-w>=0)
            h -= ends[i-w];
        if (v[i]+h<sol){
            ends[i] = sol-h-v[i];
            m_cpy -= sol-h-v[i];
            h = sol-v[i];
        }
        if (m_cpy<0)
            return 0;
    }
    return 1;
}

int bsearch(int li, int ls){
    int sol=li;

    while (li<=ls){
        int miu=(li+ls)/2;

        if (isSol(miu)){
            sol = miu;
            li = miu+1;
        }
        else{
            ls = miu-1;
        }
    }
    return sol;
}

int main()
{
    int sol;

    scanf("%d %d %d", &n, &m, &w);
    v.resize(n);
    for (int i=0; i<n; ++i){
        scanf("%d", &v[i]);
        vmin = vmin<v[i] ? vmin : v[i];
    }
    sol = bsearch(vmin, vmin+m);
    printf("%d", sol);
    return 0;
}

