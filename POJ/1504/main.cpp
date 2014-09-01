#include <cstdio>

int rev(int x){
    int rez = 0;

    while (x){
        rez = rez*10 + x%10;
        x /= 10;
    }
    return rez;
}

int main()
{
    int n;

    scanf("%d", &n);
    for (; n--;){
        int x, y;

        scanf("%d %d", &x, &y);
        printf("%d\n", rev(rev(x)+rev(y)));
    }
    return 0;
}
