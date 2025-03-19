#include<stdio.h> 
#include<stdbool.h> 
#include<malloc.h> 
#include<string.h> 
#define MAX 100001 
  
int edges[MAX][2]; 
int depth[MAX] ,sub[MAX]; 
  
void swap(int *a,int *b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
typedef struct Node{ 
    int i; 
    struct Node *next; 
}node ,*list; 
list start[MAX] ,tail[MAX]; 
void addEdge(int u ,int v){ 
    list tmp = (list)malloc(sizeof(node)); 
    tmp->i = v; 
    tmp->next = NULL; 
    if(start[u] == NULL){ 
        start[u] = tail[u] = tmp; 
    }else{ 
        tail[u]->next = tmp; 
        tail[u] = tmp; 
    } 
} 
void dfs(int s,int p){ 
    list q = start[s]; 
    if(p != -1) depth[s] = depth[p] + 1; 
    while(q){ 
        if(q->i == p){ 
            q = q->next; 
            continue; 
        } 
        dfs(q->i ,s); 
        sub[s] += sub[q->i]; 
        q = q->next; 
    } 
    sub[s]++; 
} 
int main(){ 
    int n ,x ,y ,i; 
    scanf("%d" ,&n); 
    scanf("%d%d" ,&x ,&y); 
    for(i = 0;i<n-1;i++){ 
        scanf("%d%d" ,&x ,&y); 
        x-- ,y--; 
        edges[i][0] = x ,edges[i][1]  = y; 
        addEdge(x ,y); 
        addEdge(y ,x); 
    } 
    dfs(0 ,-1); 
    for(i = 0 ; i < n-1 ; i++){ 
        x = edges[i][0] ,y = edges[i][1]; 
        if(depth[y] < depth[x]) swap(&x ,&y); 
        printf("%lld\n" ,1LL*(n-sub[y])*sub[y]); 
    } 
    return 0; 
}