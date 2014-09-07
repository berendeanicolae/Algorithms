#include <cstdio>
#include <cmath>

/*
    In the final distribution, we will have the values from 1 to m with the
  probabilities
         1                 2                3             ...           m
    X =
     (1^n-0^n)/m^n    (2^n-1^n)/m^n    (3^n-2^n)/m^n           (m^n-(m-1)^n)/m^n
  where k^n-(k-1)^n is the number of ways we can combine first k values such that the
  maximum value is k.

    So the solution to this problem is sum(i*P(i)).
    If we take sum(i*P(i)), we get m - (1/m)^n - ... - ((m-1)/m)^n.
*/


int main()
{
    double m, n, sol;

    scanf("%lf %lf", &m, &n);
    sol = m;
    for (int i=1; i<m; ++i){
        sol -= pow(i/m, n);
    }
    printf("%lf", sol);
    return 0;
}

