#include <cstdio>
#include <bitset>
#define SIZE 105
using namespace std;

int n;
bitset<SIZE> playersCards[SIZE];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        int cards;

        scanf("%d", &cards);
        for (int j=0; j<cards; ++j){
            int card;

            scanf("%d", &card);
            playersCards[i][card] = 1;
        }
    }
    for (int i=0; i<n; ++i){
        bool win = 1;

        for (int j=0; j<n; ++j){
            if (i==j)
                continue;
            if ( (playersCards[i]^playersCards[j]).count() ){
                if ( (playersCards[i]^playersCards[j]).count() == playersCards[i].count()-playersCards[j].count() ){
                    win = 0;
                }
            }
            else{
                win = 0;
            }
        }
        puts(win ? "YES" : "NO");
    }

    return 0;
}
