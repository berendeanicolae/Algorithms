#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;

    scanf("%d %d %d %d", &n, &m, &a, &b);
    printf("%d", min(min(n*a, (n%m)*a+(n-(n%m))/m*b), (n-(n%m))/m*b + (n%m ? b : 0)));
    return 0;
}
