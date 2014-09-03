#include <cstdio>
#include <algorithm>
using namespace std;

long long n, k, sum;
char s[100005];
long long letter[26];

int main()
{
    scanf("%I64d %I64d %s", &n, &k, s);
    for (char *p=s; *p; ++p){
        ++letter[*p-'A'];
    }
    sort(letter, letter+26);
    for (int i=25; k && i>=0; --i){
        if (k<letter[i]){
            sum += k*k;
            k = 0;
        }
        else{
            sum += letter[i]*letter[i];
            k -= letter[i];
        }
    }
    printf("%I64d", sum);
    return 0;
}
