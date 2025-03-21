#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N (1000)
#define MAX_M (10000)
typedef struct { int v, t; } pair;
typedef struct { pair * xs; int cnt, cap; } list;
list adj[MAX_N+1];
bool sn[MAX_N+1];
void list_add(list * lst, pair x) { 
    if ( lst->cnt == lst->cap ) { 
        lst->cap = lst->cap ? lst->cap*2 : 2; 
        lst->xs = realloc(lst->xs, lst->cap * sizeof(*lst->xs)); 
    } 
    lst->xs[lst->cnt++] = x; 
} 
void clear_seen() { 
    memset(sn, 0, (MAX_N+1)*sizeof(*sn)); 
} 
int dfs(int x,int use) { 
    int i,acc; 
    sn[x] = true; 
    for ( i=0, acc=1; i < adj[x].cnt; ++i ) { 
        pair p = adj[x].xs[i]; 
        if ( !sn[p.v] && (p.t == use || p.t == 3) ) { 
            acc += dfs(p.v, use);}} 
    return acc;} 
bool connected(int use, int n) { 
    int i; 
    clear_seen(); 
    dfs(1, use); 
    for ( i=1; i <= n; ++i ) { 
        if ( !sn[i] ) { 
            return false;}} 
    return true;} 
int main() { 
    int i, n, m, x, y, t, ccs, ectr; 
    scanf("%d %d", &n, &m); 
    for ( i=0; i < m; ++i ) { 
        scanf("%d %d %d", &x, &y, &t); 
        list_add(&adj[x], (pair) { .v = y, .t = t }); 
        list_add(&adj[y], (pair) { .v = x, .t = t });} 
    if ( connected(1, n) && connected(2, n) ) { 
        clear_seen(); 
        ectr = ccs = 0; 
        for ( i=1; i <= n; ++i ) { 
            if ( !sn[i] ) { 
                ectr += dfs(i, 0) - 1; 
                ccs += 1;}} 
        printf("%d\n", m - ectr - 2 * (ccs - 1)); 
    } else { 
        printf("-1\n"); 
    } 
    return EXIT_SUCCESS;}