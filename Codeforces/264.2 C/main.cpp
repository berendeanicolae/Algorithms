#include <cstdio>
#include <vector>
using namespace std;

int n, x1, y1, x2, y2;
long long max1, max2;
int a[2001][2001];
long long v[2][4001]; //sum on the diagonals (first\ and second/)

//we have to place the bishops on different parity cells, otherwise they will atack each other
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            scanf("%d", &a[i][j]);
            v[0][j-i+n-1] += a[i][j]; //first diagonal
            v[1][i+j-2] += a[i][j]; //second diagonal
        }
    }
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            switch ((i+j)%2){
            case 0:
                if (v[0][j-i+n-1]+v[1][i+j-2]-a[i][j] >= max1){
                    max1 = v[0][j-i+n-1]+v[1][i+j-2]-a[i][j];
                    x1 = i;
                    y1 = j;
                }
                break;
            case 1:
                if (v[0][j-i+n-1]+v[1][i+j-2]-a[i][j] >= max2){
                    max2 = v[0][j-i+n-1]+v[1][i+j-2]-a[i][j];
                    x2 = i;
                    y2 = j;
                }
                break;
            }
        }
    }
    printf("%I64d\n%d %d %d %d", max1+max2, x1, y1, x2, y2);
    return 0;
}
