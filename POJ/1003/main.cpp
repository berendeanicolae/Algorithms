#include <cstdio>

int main()
{
    double s;

    while (scanf("%lf", &s)!=EOF && s){
        int i;

        for (i=1; s>0;){
            s -= 1./++i;
        }
        printf("%d card(s)\n", i-1);
    }
    return 0;
}