#include <cstdio>

int main()
{
    int n, m, r=0, sol;

    scanf("%d %d", &n, &m);
    for (sol=0; n; --n, ++sol){
        ++r;
        if (r==m){
            r = 0;
            ++n;
        }
    }
    printf("%d", sol);
    return 0;
}
