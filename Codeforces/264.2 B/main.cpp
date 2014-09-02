#include <cstdio>
#include <algorithm>

int n, max;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        int h;

        scanf("%d", &h);
        max = max > h ? max : h;
    }
    printf("%d", max);
    return 0;
}
