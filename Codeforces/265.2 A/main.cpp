#include <cstdio>

int main()
{
    int n, sol;
    char s[105];

    scanf("%d%s", &n, s);
    for (sol=1; sol<n; ++sol){
        if (s[sol-1]=='0')
            break;
    }
    printf("%d", sol);
    return 0;
}
