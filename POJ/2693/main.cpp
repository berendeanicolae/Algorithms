#include <cstdio>
#include <cmath>
#include <vector>
#define RADIUS 2.5
#define EPSILON 0.0000000001
using namespace std;

struct point{
    double x, y;
};

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    double x, y;
    vector<point> points;
    int sol=1;

    while (scanf("%lf %lf", &x, &y)!=EOF){
        point p={x, y};
        points.push_back(p);
    }
    for (unsigned i=0; i<points.size(); ++i){
        for (unsigned j=i+1; j<points.size(); ++j){
            if (dist(points[i].x, points[i].y, points[j].x, points[j].y) > 2*RADIUS)
                continue;
            double x1, y1, x2, y2; //center of the two circles I can build

            double xm=(points[i].x+points[j].x)/2, ym=(points[i].y+points[j].y)/2;
            double d1 = dist(points[i].x, points[i].y, points[j].x, points[j].y);
            double d2 = sqrt(RADIUS*RADIUS-(d1/2)*(d1/2));

            x1 = xm + d2*(points[i].y-points[j].y)/d1;
            y1 = ym + d2*(points[j].x-points[i].x)/d1;
            x2 = xm - d2*(points[i].y-points[j].y)/d1;
            y2 = ym - d2*(points[j].x-points[i].x)/d1;

            int count1=0, count2=0;
            for (unsigned k=0; k<points.size(); ++k){
                if (dist(points[k].x, points[k].y, x1, y1)<=RADIUS+EPSILON)
                    ++count1;
                if (dist(points[k].x, points[k].y, x2, y2)<=RADIUS+EPSILON)
                    ++count2;
            }
            sol = sol>count1 ? sol : count1;
            sol = sol>count2 ? sol : count2;
        }
    }
    printf("%d", sol);
    return 0;
}
