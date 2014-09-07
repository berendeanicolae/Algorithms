#include <cstdio>

int main()
{
    int n;
    unsigned min=0xffffffff, cmin=0, max=0, cmax=0;

    scanf("%d", &n);
    for (; n--;){
        unsigned x;

        scanf("%d", &x);
        cmin += x==min;
        cmax += x==max;
        if (x<min){
            min = x;
            cmin = 1;
        }
        if (x>max){
            max = x;
            cmax = 1;
        }
    }
    printf("%d %I64d", max-min, min!=max ? (long long)cmin*cmax : (long long)cmin*(cmax-1)/2);
    return 0;
}

