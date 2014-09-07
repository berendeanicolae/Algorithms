#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, li=1, ls=1;
    int c1=0, c2=0;
    vector<unsigned> v;

    scanf("%d", &n);
    v.resize(n+2);

    for (int i=1; i<=n; ++i){
        scanf("%d", &v[i]);
    }
    v[n+1] = 0xffffffff;

    for (int i=1; i<=n; ++i){
        if (v[i-1]<v[i] && v[i]>v[i+1]){
            ++c1;
            li = i;
        }
        if (v[i-1]>v[i] && v[i]<v[i+1]){
            ++c2;
            ls = i;
        }
    }
    if (c1<=1 && c2<=1){
        if (c1 && c2){
            if (v[ls]>v[li-1] && v[li]<v[ls+1]){
                printf("yes\n%d %d", li, ls);
                return 0;
            }
        }
        if (c1 && !c2){
            if (v[n]>v[li]){
                printf("yes\n%d %d", li, n);
                return 0;
            }
        }
        if (!c1 && !c2){
            printf("yes\n%d %d", li, ls);
            return 0;
        }
    }

    puts("no");
    return 0;
}
