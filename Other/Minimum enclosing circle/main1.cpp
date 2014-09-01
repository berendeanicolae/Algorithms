#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define EPSILON 0.0000001

class Point{
public:
    double x, y;
    void operator+=(Point& other){x+=other.x;y+=other.y;}
    void operator-=(Point& other){x-=other.x;y-=other.y;}
};

class Circle{
public:
    Point center;
    double r;
};

std::vector<Point> points;

void readPoints(std::vector<Point> &points);
Circle minEnclosingCircle(std::vector<Point> &points);

int main()
{
    int t;

    freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        readPoints(points);
        Circle sol = minEnclosingCircle(points);
        printf("%lf %lf %lf\n", sol.center.x, sol.center.y, sol.r);
    }
    return 0;
}

void readPoints(std::vector<Point> &points){
    int n;

    scanf("%d", &n);
    points.clear();
    for (int i=0; i<n; ++i){
        Point point;

        scanf("%lf %lf", &point.x, &point.y);
        points.push_back(point);
    }
}

//return the squared distance between two points
static double distance(const Point &p1, const Point &p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

void extend(Point &b, Point &c, Circle &sol){
    double d = 2*(b.x*c.y-b.y*c.x);
    sol.center.x = (c.y*(b.x*b.x+b.y*b.y)-b.y*(c.x*c.x+c.y*c.y))/d;
    sol.center.y = (b.x*(c.x*c.x+c.y*c.y)-c.x*(b.x*b.x+b.y*b.y))/d;
}

Circle minEnclosingCircle(std::vector<Point> &points){
	Circle sol = {{0,0}, 0};
    std::vector<Point> cpoints;
    Point point;

    srand(time(0));
    for (unsigned i=0; i<points.size(); ++i){
        int j = rand()%(points.size()-i)+i;
        std::swap(points[i], points[j]);

        double dist = distance(sol.center, points[i]);
        //daca e pe circumferinta
        if (abs(dist-sol.r)<=EPSILON){
            cpoints.push_back(points[i]);
        }
        //daca e in afara cercului
        if (dist>sol.r+EPSILON){
            //pair<double, double> aux;
            switch (cpoints.size()){
                case 0:
                    cpoints.push_back(points[i]);
                    sol.center = points[i];
                    break;
                case 1:
                    cpoints.push_back(points[i]);
                    sol.center.x = (cpoints[0].x+cpoints[1].x)/2;
                    sol.center.y = (cpoints[0].y+cpoints[1].y)/2;
                    sol.r = dist/4;
                    break;
                case 2:
                    cpoints[0] -= points[i];
                    cpoints[1] -= points[i];
                    extend(cpoints[0], cpoints[1], sol); //not good
                    cpoints[0] += points[i];
                    cpoints[1] += points[i];
                    sol.center += points[i];
					sol.r = distance(sol.center, points[i]);
                    cpoints.push_back(points[i]);
					break;
                default:
                    point = points[i];
                    dist = 0;
                    for (unsigned j=0; j<cpoints.size(); ++j){
                        if (distance(cpoints[j], points[i])>dist){
                            dist = distance(cpoints[j], points[i]);
                            point = points[j];
                        }
                    }
                    cpoints.resize(0);
                    cpoints.push_back(point);
                    cpoints.push_back(points[i]);
                    sol.center.x = (cpoints[0].x+cpoints[1].x)/2;
                    sol.center.y = (cpoints[0].y+cpoints[1].y)/2;
                    sol.r = dist/4;
                    break;
            }
        }
    }

    sol.r = sqrt(sol.r);
    return sol;
}
