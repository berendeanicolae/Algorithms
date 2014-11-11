#include <cstdio>
#include <vector>
using namespace std;

int f(int x, int y){
    return x/y+(x%y ? 1 : 0);
}

int main()
{
    int n, m, max = 0;
    vector<int> v;

    scanf("%d %d", &n, &m);
    v.resize(n);
    for (int i=0; i<n; ++i){
        scanf("%d", &v[i]);
        if (f(v[i],m)>=f(v[max],m)){
            max = i;
        }
    }
    printf("%d", max+1);
    return 0;
}
