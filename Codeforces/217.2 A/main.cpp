#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int r1, c1, r2, c2;

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    printf("%d ", r1==r2 || c1==c2 ? 1 : 2);

    if (abs(r1-c1)%2!=abs(r2-c2)%2){
        printf("0 ");
    }
    else{
        if (r1-c1==r2-c2)
            printf("1 ");
        else if (r1+c1==r2+c2)
            printf("1 ");
        else
            printf("2 ");
    }

    printf("%d", max(abs(r1-r2), abs(c1-c2)));
    return 0;
}
