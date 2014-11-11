#include <cstdio>

int a, b, c;

int main()
{
    int ab, bc, ac;

    scanf("%d %d %d", &a, &b, &c);
    ab = (a+b-c)/2;
    bc = (b+c-a)/2;
    ac = (a+c-b)/2;
    if (ab<0 || bc<0 || ac<0 || 2*(ab+bc+ac)!=a+b+c){
        printf("Impossible");
        return 0;
    }
    printf("%d %d %d", ab, bc, ac);
    return 0;
}
