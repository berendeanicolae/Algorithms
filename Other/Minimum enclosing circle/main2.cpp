#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define EPSILON 0.0000001
#define PI 3.14159265358979323846
using namespace std;

struct circle{
    pair<double, double> c; //center (x,y)
    double r; //radius
};

vector<pair<double, double>> points;

void readPoints(int &n, vector<pair<double, double>> &points);
circle minEnclosingCircle(vector<pair<double, double>> &points);

int main()
{
    int n;

    readPoints(n, points);
    circle sol = minEnclosingCircle(points);
    printf("%lf %lf %lf\n", sol.c.first, sol.c.second, sol.r);
    return 0;
}

void readPoints(int &n, vector<pair<double, double>> &points){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    scanf("%d", &n);
    points.clear();
    for (int i=0; i<n; ++i){
        pair<double, double> point;

        scanf("%lf %lf", &point.first, &point.second);
        points.push_back(point);
    }
}

//return the squared distance between two points
static double distance(const pair<double, double> &p1, const pair<double, double> &p2){
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

int c; //points on circle's circumference
pair<double, double> cpoints[2]; //save them

double surface(pair<double, double> &a, pair<double, double> &b, pair<double, double> &c){
    return a.first*b.second+b.first*c.second+c.first*a.second-
           b.second*c.first-c.second*a.first-a.second*b.first;
}

bool checkPoints(vector<pair<double, double> > &points, circle &sol){
    unsigned i;

    for (i=0, c=0; c<1; ++i){
        if (distance(sol.c, points[i])-sol.r < EPSILON){
            cpoints[c++] = points[i];
        }
    }
    if (surface(cpoints[0], sol.c, cpoints[1]) < 0){
        swap(cpoints[0], cpoints[1]);
    }
    for (++i; i<points.size(); ++i){
        break;
    }
    return surface(cpoints[0], sol.c, cpoints[1])>0;
}

void moveCenter(vector<pair<double, double> > &points, circle &sol){
}

/*
    1) build a circle that contains all the points
    2) shrink it until it has at least two points on it's circumference
*/
circle minEnclosingCircle(vector<pair<double, double>> &points){
    circle sol{{0, 0}, 0};

    c = 0;
    for (auto p : points){
        double dist = distance(sol.c, p);

        if (dist-sol.r > EPSILON){
            sol.r = dist;
            c = 1;
            cpoints[0] = p;
            continue;
        }
        c += dist-sol.r>=0 && dist-sol.r<EPSILON;
    }

    if (c<2){
        double r = 0;

        for (auto p : points){
            double a = cpoints[0].first*cpoints[0].first+cpoints[0].second*cpoints[0].second;
            double b = p.first*p.first+p.second*p.second;
            double c = distance(cpoints[0], p);
            double angle = acos((a+b-c)/(2*sqrt(a)*sqrt(b)));

            double dist = c/(2*(1-cos(PI-2*angle)));
            if (dist-r > EPSILON)
                r = dist;
        }
        sol.r = r;
    }

    while (checkPoints(points, sol)){
        moveCenter(points, sol);
    }

    sol.r = sqrt(sol.r);
    return sol;
}