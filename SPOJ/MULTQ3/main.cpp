#include <cstdio>
#include <bitset>
#include <algorithm>
#define SIZE 400005
using namespace std;

int N, Q;
int tree[SIZE][3];

void init(int li, int ls);
void read();
void update(int li, int ls, int pos, int l, int r);
int query(int li, int ls, int pos, int l, int r);
void solve();

int main()
{
    read();
    solve();
    return 0;
}

void init(int pos, int li, int ls){
    tree[pos][0] = ls-li+1;
    if (li<ls){
        init(pos*2+1, li, (li+ls)/2);
        init(pos*2+2, (li+ls)/2+1, ls);
    }
}

void read(){
    freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    init(0, 0, N-1);
}

void update(int li, int ls, int pos, int l, int r){
    if (li<=l && r<=ls){
        swap(tree[pos][0], tree[pos][1]);
        swap(tree[pos][0], tree[pos][2]);
        return;
    }

    int m = (l+r)/2;
    if (m >= ls){
        update(li, ls, pos*2+1, l, m);
        tree[pos][0] = tree[pos*2+1][0]+tree[pos*2+2][0];
        tree[pos][1] = tree[pos*2+1][1]+tree[pos*2+2][1];
        tree[pos][2] = tree[pos*2+1][2]+tree[pos*2+2][2];
        return;
    }
    if (m < li){
        update(li, ls, pos*2+2, m+1, r);
        tree[pos][0] = tree[pos*2+1][0]+tree[pos*2+2][0];
        tree[pos][1] = tree[pos*2+1][1]+tree[pos*2+2][1];
        tree[pos][2] = tree[pos*2+1][2]+tree[pos*2+2][2];
        return;
    }

    update(li, ls, pos*2+1, l, m);
    update(li, ls, pos*2+2, m+1, r);
    tree[pos][0] = tree[pos*2+1][0]+tree[pos*2+2][0];
    tree[pos][1] = tree[pos*2+1][1]+tree[pos*2+2][1];
    tree[pos][2] = tree[pos*2+1][2]+tree[pos*2+2][2];
}

int query(int li, int ls, int pos, int l, int r){
    if (li<=l && r<=ls)
        return tree[pos][0];

    int m = (l+r)/2;
    if (m >= ls)
        return query(li, ls, pos*2+1, l, m);
    if (m < li)
        return query(li, ls, pos*2+2, m+1, r);
    return query(li, ls, pos*2+1, l, m) + query(li, ls, pos*2+2, m+1, r);
}

void solve(){
    for (int q=0; q<Q; ++q){
        int op, a, b;

        scanf("%d %d %d", &op, &a, &b);
        switch (op){
            case 0:
                update(a, b, 0, 0, N-1);
                break;
            case 1:
                printf("%d\n", query(a, b, 0, 0, N-1));
                break;
        }
    }
}
