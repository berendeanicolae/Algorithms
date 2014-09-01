#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
    bitset<26> sol;
    int n;

    scanf("%d", &n);
    sol.set();
    for (; n--;){
        char s[100];
        bitset<26> rock;

        scanf("%s", s);
        for (char *p=s; *p; ++p){
            rock[*p-'a'] = 1;
        }
        sol &= rock;
    }

    printf("%d", sol.count());
    return 0;
}
