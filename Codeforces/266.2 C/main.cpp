#include <cstdio>
#include <algorithm>
#define SIZE 500005
using namespace std;

/*
    n - number of integers
    v[i] with 1<=i<=n
    lsum[i] with 1<=i<=n sum(v[1->i])
    rsum[i] with 1<=i<=n sum(v[i->n])
    tsum - total sum
*/
long long n, v[SIZE], lsum[SIZE], rsum[SIZE], tsum;
pair<long long, long long> sum[SIZE];

void read(){
    scanf("%I64d", &n);
    for (int i=1; i<=n; ++i){
        scanf("%I64d", &v[i]);
    }
}

void init(){
    for (int l=1, r=n; l<=n; ++l, --r){
        lsum[l] = lsum[l-1] + v[l];
        rsum[r] = rsum[r+1] + v[r];
        sum[r].first = rsum[r];
        sum[r].second = r;
    }
    tsum = lsum[n];
    sort(sum+1, sum+n+1);
}


//find the smallest possition where we find value
int bsearch1(int li, int ls, long long value, int pos){
    int m;

    while (li<=ls){
        m=(li+ls)/2;

        if (sum[m].first>=value){
            //check pos
            if (sum[m].first==value && sum[m].second<=pos){
                li = m+1;
                continue;
            }
            ls = m-1;
        }
        else{
            li = m+1;
        }
    }
    m = (li+ls)/2;
    if (sum[m].first<value || (sum[m].first==value && sum[m].second<=pos) ){
        ++m;
    }
    return m;
}

//find the largest position where we find value
int bsearch2(int li, int ls, long long value){
    int m;

    while (li<=ls){
         m=(li+ls)/2;

         if (sum[m].first <= value){
             li = m+1;
         }
         else{
             ls = m-1;
         }
    }
    m = (li+ls)/2;
    if (sum[m].first > value || m==n){
        --m;
    }
    return m;
}

int main()
{
    read();
    init();

    if (tsum%3){
        printf("0");
    }
    else{
        long long sol = 0;

        for (int i=1; i<n-1; ++i){
            if (2*lsum[i]!=rsum[i+1])
                continue;

            int li, ls;

            li = bsearch1(1, n, lsum[i], i);
            ls = bsearch2(1, n, lsum[i]);

            if (sum[li].first != lsum[i])
                continue;

            sol += ls-li+1;
        }
        printf("%I64d", sol);
    }

    return 0;
}
