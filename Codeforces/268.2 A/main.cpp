#include <cstdio>
#include <bitset>
using namespace std;

int n;
bitset<105> levels;

void read(){
    int c;

    scanf("%d", &c);
    for (int i=0; i<c; ++i){
        int x;

        scanf("%d", &x);
        levels[x] = 1;
    }
}

int main()
{
    scanf("%d", &n);
    read();
    read();
    printf("%s", levels.count()==n ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}
