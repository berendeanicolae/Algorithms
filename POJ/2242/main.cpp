#include <cstdio>
#include <cmath>
#define PI 3.141592653589793

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    double x1, y1, x2, y2, x3, y3;

    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF){
        double x, y, d, r;

        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;

        d = 2*(x2*y3-y2*x3);
        x = (y3*(x2*x2+y2*y2)-y2*(x3*x3+y3*y3))/d;
        y = (x2*(x3*x3+y3*y3)-x3*(x2*x2+y2*y2))/d;
        r = dist(x, y, x2, y2);
        printf("%.2f\n", 2*PI*r);
    }
    return 0;
}
