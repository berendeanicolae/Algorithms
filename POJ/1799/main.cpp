#include <cstdio>
#include <cmath>
#define PI 3.14159265359
int main()
{
    int T;

    scanf("%d", &T);
    for (int t=1; t<=T; ++t){
        int n;
        double R;

        scanf("%lf %d", &R, &n);

        double angle = 2*PI/n;
        double l = sqrt(2*R*R*(1-cos(angle)));
        double r;
        r = l*R/(2*R+l);
        printf("Scenario #%d:\n%.3f\n\n", t, r);
    }
    return 0;
}
