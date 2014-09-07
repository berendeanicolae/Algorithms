#include <cstdio>

int main()
{
    int t;

    scanf("%d", &t);
    while (t--){
        unsigned x, l, r, i;

        scanf("%d", &x);
        l = r = x;
        for (i=0; !(x&(1<<i)); ++i){
            r |= 1<<i;
        }
        l &= ~(1<<i);
        l |= 1;
        printf("%d %d\n", l, r);
    }
    return 0;
}
