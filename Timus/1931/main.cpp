#include <cstdio>

int main()
{
    int n, best, maxcomps=0, comps=0;
    int is = 0;

    //freopen("txt.in", "r", stdin);
    scanf("%d %d", &n, &best);
    for (int i=1, cis=0; i<n; ++i){
        int c;

        scanf("%d", &c);
        if (best<c){
            ++comps;
        }
        else{
            cis = i;
            comps = 1;
            best = c;
        }
        if (comps > maxcomps){
            maxcomps = comps;
            is = cis;
        }
    }
    printf("%d", is+1);
}
