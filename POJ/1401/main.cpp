#include <cstdio>

int main()
{
    int n;

    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        int x, sum=0;

        scanf("%d", &x);
        while (x){
            sum += x/5;
            x /= 5;
        }
        printf("%d\n", sum);
    }
    return 0;
}
