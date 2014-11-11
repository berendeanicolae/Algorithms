#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);

    if (n<4){
        puts("NO");
        return 0;
    }
    if (n%2){
        puts("YES");
        puts("4 * 5 = 20\n"
             "20 + 2 = 22\n"
             "22 + 3 = 25\n"
             "25 - 1 = 24");
        for (int i=7; i<=n; i+=2){
            printf("%d - %d = 1\n24 * 1 = 24\n", i, i-1);
        }
    }
    else{
        puts("YES");
        puts("1 * 2 = 2\n"
             "2 * 3 = 6\n"
             "6 * 4 = 24");
        for (int i=6; i<=n; i+=2){
            printf("%d - %d = 1\n24 * 1 = 24\n", i, i-1);
        }
    }
    return 0;
}
