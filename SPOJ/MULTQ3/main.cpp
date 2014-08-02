#include <cstdio>
#include <algorithm>
#define SIZE 400005
using namespace std;

struct node{
    int value[3];
    int add;
};

int N, Q;
node tree[SIZE];

void read();
void solve();

int main()
{
    read();
    solve();
    return 0;
}

void init(int pos, int li, int ls){
    tree[pos].value[0] = ls-li+1;
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

void push(int pos){
    tree[pos].add %= 3;
    if (tree[pos].value[0]+tree[pos].value[1]+tree[pos].value[2]  > 1){
        tree[pos*2+1].add = tree[pos*2+2].add = tree[pos].add;
    }
    switch (tree[pos].add){
        case 1:
            swap(tree[pos].value[0], tree[pos].value[1]);
            swap(tree[pos].value[0], tree[pos].value[2]);
            break;
        case 2:
            swap(tree[pos].value[0], tree[pos].value[2]);
            swap(tree[pos].value[0], tree[pos].value[1]);
            break;
    }
    tree[pos].add = 0;
}

void pull(int pos){
    tree[pos].value[0] = tree[pos*2+1].value[0]+tree[pos*2+2].value[0];
    tree[pos].value[1] = tree[pos*2+1].value[1]+tree[pos*2+2].value[1];
    tree[pos].value[2] = tree[pos*2+1].value[2]+tree[pos*2+2].value[2];
}

void update(int li, int ls, int pos, int l, int r){
    if (li<=l && r<=ls){
        ++tree[pos].add;
        push(pos);
        return;
    }

    int m = (l+r)/2;
    if (m >= ls){
        update(li, ls, pos*2+1, l, m);
        pull(pos);
        return;
    }
    if (m < li){
        update(li, ls, pos*2+2, m+1, r);
        pull(pos);
        return;
    }

    update(li, ls, pos*2+1, l, m);
    update(li, ls, pos*2+2, m+1, r);
    pull(pos);
}

int query(int li, int ls, int pos, int l, int r){
    if (li<=l && r<=ls){
        if (tree[pos].add){
            push(pos);
        }
        return tree[pos].value[0];
    }

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
