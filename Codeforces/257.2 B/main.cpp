#include <cstdio>

int main()
{
    long long n, x, y, rez;

    scanf("%I64d %I64d %I64d", &x, &y, &n);
    n = (n-1)%6+1;
    switch (n){
        case 1:
            rez = x;
            break;
        case 2:
            rez = y;
            break;
        case 3:
            rez = y-x;
            break;
        case 4:
            rez = -x;
            break;
        case 5:
            rez = -y;
            break;
        case 6:
            rez = -y+x;
            break;
    }
    printf("%I64d", (rez%1000000007+1000000007)%1000000007);
    return 0;
}
