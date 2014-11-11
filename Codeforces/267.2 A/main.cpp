#include <cstdio>

int n, p, q, sol;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d %d", &p, &q);
        sol += q-p>=2;
    }
    printf("%d", sol);
    return 0;
}
