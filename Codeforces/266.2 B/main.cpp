#include <cstdio>
#include <algorithm>
using namespace std;

long long n, a, b, sola, solb;
bool swp;

void solve(){
    sola = a;
    solb = b;
    for (int i=a, lim=sqrt(6*n); i<=lim; ++i){
        long long ta=i, tb;

        tb = 6*n/ta;
        tb = tb<b ? b : tb;
        if (ta*tb<6*n)
            ++tb;
        if (sola*solb < 6*n){
            sola = ta;
            solb = tb;
            continue;
        }
        if (sola*solb > ta*tb){
            sola = ta;
            solb = tb;
        }
    }
}

int main()
{
    scanf("%I64d %I64d %I64d", &n, &a, &b);

    if (a<b){
        solve();
    }
    else{
        swap(a, b);
        solve();
        swap(sola, solb);
    }
    printf("%I64d\n%I64d %I64d", sola*solb, sola, solb);
    return 0;
}
