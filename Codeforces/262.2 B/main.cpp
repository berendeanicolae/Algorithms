#include <cstdio>
#include <vector>
using namespace std;

int sum(int x){
    int s=0;
    while (x){
        s += x%10;
        x /= 10;
    }
    return s;
}

long long pow(int x, int p){
    long long pw = x;
    while (--p){
        pw *= x;
    }
    return pw;
}

int main()
{
    int a, b, c;
    vector<int> sol;

    scanf("%d %d %d", &a, &b, &c);
    for (int s=1; s<=81; ++s){
        if (sum(b*pow(s, a)+c)==s)
            if (b*pow(s, a)+c < 1000000000)
                sol.push_back(b*pow(s, a)+c);
    }
    printf("%d\n", sol.size());
    for (unsigned i=0; i<sol.size(); ++i){
        printf("%d ", sol[i]);
    }
    return 0;
}
