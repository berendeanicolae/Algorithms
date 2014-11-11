#include <cstdio>
#include <algorithm>
using namespace std;

int T;
long long n, k, d1, d2;

bool check1(){
    long long c1, c2, c3;

    if ((c1=2*d1+k+d2)%3)
        return 0;
    c1 /= 3;
    c2 = c1-d1;
    c3 = c2-d2;
    if (c1<0 || c2<0 || c3<0)
        return 0;
    if (c1+c2+c3 > k)
        return 0;

    return n-k>=2*d1+d2 && !((n-k-2*d1-d2)%3);
}

bool check2(){
    long long c1, c2, c3;

    if ((c1=k-2*d1+d2)%3)
        return 0;
    c1 /= 3;
    c2 = d1+c1;
    c3 = c2-d2;
    if (c1<0 || c2<0 || c3<0)
        return 0;
    if (c1+c2+c3 > k)
        return 0;

    return n-k>=d1+d2 && !((n-k-d1-d2)%3);
}

bool check3(){
    long long c1, c2, c3;

    if ((c1=k+2*d1-d2)%3)
        return 0;
    c1 /= 3;
    c2 = c1-d1;
    c3 = c2+d2;
    if (c1<0 || c2<0 || c3<0)
        return 0;
    if (c1+c2+c3 > k)
        return 0;

    return n-k>=2*max(c1,c3)-min(c1,c3)-c2 && !((n-k-2*max(c1,c3)+min(c1,c3)+c2)%3);
}

bool check4(){
    long long c1, c2, c3;

    if ((c1=k-2*d1-d2)%3)
        return 0;
    c1 /= 3;
    c2 = c1+d1;;
    c3 = c2+d2;
    if (c1<0 || c2<0 || c3<0)
        return 0;
    if (c1+c2+c3 > k)
        return 0;

    return n-k>=2*d2+d1 && !((n-k-2*d2-d1)%3);
}

int main()
{

    scanf("%d", &T);
    while (T--){
        scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
        if (check1() || check2() || check3() || check4()){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    return 0;
}
