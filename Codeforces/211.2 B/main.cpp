#include <cstdio>
#define SIZE 150005

int n, k, sum, min, sol;
int v[SIZE];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i=0; i<k; ++i){
        scanf("%d", &v[i]);
        sum += v[i];
    }
    min = sum;
    sol = k-1;
    for (int i=k; i<n; ++i){
        scanf("%d", &v[i]);
        sum += v[i]-v[i-k];
        if (sum<min){
            min = sum;
            sol = i;
        }
    }
    printf("%d", sol-k+2);
    return 0;
}
