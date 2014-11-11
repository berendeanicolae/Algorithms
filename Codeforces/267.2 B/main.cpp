#include <cstdio>

int countBits(unsigned value){
    int bits = 0;

    while (value){
        value &= value-1;
        ++bits;
    }
    return bits;
}

int main()
{
    int n, m, k, sol=0, fedor;
    int soldiers[1005];

    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=m; ++i){
        scanf("%d", &soldiers[i]);
    }
    scanf("%d", &fedor);

    for (int i=1; i<=m; ++i){
        sol += countBits(soldiers[i] ^ fedor)<=k;
    }
    printf("%d", sol);
    return 0;
}
