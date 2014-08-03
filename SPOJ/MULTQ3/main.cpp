#include <cstdio>
#include <algorithm>
#define SIZE 400005
using namespace std;

struct node{
    int value[3];
    int add;
};

int N, Q, li, ls;
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
        init((pos<<1)+1, li, (li+ls)/2);
        init((pos<<1)+2, (li+ls)/2+1, ls);
    }
}

int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

void read(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    N = readint();
    Q = readint();
    //scanf("%d %d", &N, &Q);
    init(0, 0, N-1);
}

void push(int pos){
    tree[pos].add %= 3;
    if (tree[pos].value[0]+tree[pos].value[1]+tree[pos].value[2]  > 1){
        tree[(pos<<1)+1].add += tree[pos].add;
		tree[(pos<<1)+2].add += tree[pos].add;
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
    tree[pos].value[0] = tree[(pos<<1)+1].value[0]+tree[(pos<<1)+2].value[0];
    tree[pos].value[1] = tree[(pos<<1)+1].value[1]+tree[(pos<<1)+2].value[1];
    tree[pos].value[2] = tree[(pos<<1)+1].value[2]+tree[(pos<<1)+2].value[2];
}

void update(int pos, int l, int r){
    if (li<=l && r<=ls){
        ++tree[pos].add;
        push(pos);
        return;
    }

    push(pos);
    int m = (l+r)/2;
    if (m >= ls){
        update((pos<<1)+1, l, m);
		if (l<r){
			push((pos<<1)+2);
		}
        pull(pos);
        return;
    }
    if (m < li){
        update((pos<<1)+2, m+1, r);
		if (l<r){
			push((pos<<1)+1);
		}
        pull(pos);
        return;
    }

    update((pos<<1)+1, l, m);
    update((pos<<1)+2, m+1, r);
	if (l<r){
		push((pos<<1)+1);
		push((pos<<1)+2);
	}
    pull(pos);
}

int query(int pos, int l, int r){
    push(pos);
    if (li<=l && r<=ls){
        return tree[pos].value[0];
    }

    int m = (l+r)/2;
    if (m >= ls)
        return query((pos<<1)+1, l, m);
    if (m < li)
        return query((pos<<1)+2, m+1, r);
    return query((pos<<1)+1, l, m) + query((pos<<1)+2, m+1, r);
}

void solve(){
    for (int q=0; q<Q; ++q){
        int op;

        op = readint();
        li = readint();
        ls = readint();
        //scanf("%d %d %d", &op, &li, &ls);
        switch (op){
            case 0:
                update(0, 0, N-1);
                break;
            case 1:
                printf("%d\n", query(0, 0, N-1));
                break;
        }
    }
}
