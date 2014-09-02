#include <cstdio>

int n, s, sol=-1;

int main()
{
    scanf("%d %d", &n, &s);
    for (int i=0; i<n; ++i){
        int x, y;

        scanf("%d %d", &x, &y);
        if (s*100>=x*100+y){
            if ((100-y)%100>sol){
                sol = (100-y)%100;
            }
        }
    }
    printf("%d", sol);
    return 0;
}
