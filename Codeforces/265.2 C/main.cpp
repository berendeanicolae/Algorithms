#include <cstdio>

int n, p;
char s[1005], *ps;

bool isSol(){
    for (int i=1; i<n; ++i){
        if (s[i]==s[i-1] || s[i-1]==s[i+1])
            return 0;
    }
    return 1;
}

bool inc(){
    for (int i=1; i<n; ++i){
        if (s[i]==s[i-1]){
            if (s[i]<p+'a'-1){
                ++s[i];
                for (++i; i<n; ++i){
                    s[i] = 'a';
                }
                return 1;
            }
            ps = &s[i-2];
            while (ps>=s && *ps==p+'a'-1) {--ps;}
            if (ps>=s){
                ++*ps;
                ++ps;
                while (*ps){
                    *ps = 'a';
                    ++ps;
                }
                return 1;
            }
            return 0;
        }
        if (s[i-1]==s[i+1]){
            if (s[i+1]<p+'a'-1){
                ++s[i+1];
                for (i+=2; i<n; ++i){
                    s[i] = 'a';
                }
                return 1;
            }
            if (s[i]<p+'a'-1){
                ++s[i];
                for (++i; i<n; ++i){
                    s[i] = 'a';
                }
                return 1;
            }
            ps = &s[i-2];
            while (ps>=s && *ps==p+'a'-1) {--ps;}
            if (ps>=s){
                ++*ps;
                ++ps;
                while (*ps){
                    *ps = 'a';
                    ++ps;
                }
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d %d %s", &n, &p, s);

    if ((p==1 && n>=2) || (p==2 && n>=3)){
        printf("NO");
        return 0;
    }

    ps = &s[n-1];
    while (ps>=s && *ps==p+'a'-1) {--ps;}
    if (ps<s){
        printf("NO");
        return 0;
    }

    ++*ps;
    ++ps;
    while (*ps){
        *ps++ = 'a';
    }
    while (!isSol()){
        if (!inc())
            break;
    }
    printf("%s", isSol() ? s : "NO");
    return 0;
}
