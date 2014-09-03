#include <cstdio>
#include <bitset>
#define SIZE 1000005
using namespace std;

bitset<SIZE> ciur;

void ciurInit(){
    for (int i=3; i<SIZE/3; i+=2){
        for (int j=i+i+i; j<SIZE; j+=i+i){
            ciur[j] = 1;
        }
    }
}

int main()
{
    int x;

    ciurInit();

    while (scanf("%d", &x) && x){
        int a=3;

        while (ciur[x-a] || ciur[a])
            a += 2;
        printf("%d = %d + %d\n", x, a, x-a);
    }
    return 0;
}
