#include <cstdio>

int main()
{
    int n, sol=0;
    bool in=0, out=0;

    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        int x;

        scanf("%d", &x);
        if (x){
            sol += x+out;
            in = 1;
            out = 0;
        }
        else{
            if (in){
                in = !in;
                out = 1;
            }
        }
    }
    printf("%d", sol);

    return 0;
}
