#include <cstdio>

int n;
char v[103][103];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i){
        scanf("%s", v[i]+1);
    }
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            int s = 0;
            s += v[i-1][j]=='o';
            s += v[i][j+1]=='o';
            s += v[i+1][j]=='o';
            s += v[i][j-1]=='o';
            if (s%2){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
