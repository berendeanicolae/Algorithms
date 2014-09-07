#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long n, sol=0, sum1=0;
    vector<int> v;

    scanf("%I64d", &n);
    v.resize(n);
    for (int i=0; i<n; ++i){
        scanf("%d", &v[i]);
        sum1 += v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; ++i){
        sol += sum1;
        if (i<n-1){
            sol += v[i];
        }
        sum1 -= v[i];
    }
    printf("%I64d", sol);
    return 0;
}
