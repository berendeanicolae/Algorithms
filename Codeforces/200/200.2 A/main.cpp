#include <cstdio>

int n, sol=1;

int main()
{
    int last, now;

    scanf("%d", &n);
    scanf("%d", &last);
    for (int i=2; i<=n; ++i){
        scanf("%d", &now);
        sol += last != now;
        last = now;
    }
    printf("%d", sol);
    return 0;
}
