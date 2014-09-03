#include <cstdio>

long long surface(long long x1, long long y1, long long x2, long long y2){
    return x1*y2-y1*x2;
}

int dir[][2]={{}, {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {}, {0,1}, {1,-1}, {1,0}, {1,1}};

int main()
{
    int t;

    scanf("%d", &t);
    while (t--){
        char s[1000005];
        int x=0, y=0;
        long long area=0;

        scanf("%s", s);
        for (char *p=s; *p && *p!='5'; ++p){
            int xm, ym;
            xm = x+dir[*p-'0'][0];
            ym = y+dir[*p-'0'][1];
            area += surface(x, y, xm, ym);
            x = xm;
            y = ym;
        }
        area = area>=0 ? area : -area;
        printf("%lld%s\n", area/2, area%2 ? ".5" : "");
    }
    return 0;
}
