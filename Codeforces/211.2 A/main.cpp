#include <cstdio>
using namespace std;

char digits[][10] = {"O-|-OOOO", //0
                   "O-|O-OOO", //1
                   "O-|OO-OO", //2
                   "O-|OOO-O", //3
                   "O-|OOOO-", //4
                   "-O|-OOOO", //5
                   "-O|O-OOO", //6
                   "-O|OO-OO", //7
                   "-O|OOO-O", //8
                   "-O|OOOO-", //9
};

void solve(int n, int lv){
    if (n || !lv){
        printf("%s\n", digits[n%10]);
        solve(n/10, lv+1);
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    solve(n, 0);
    return 0;
}
