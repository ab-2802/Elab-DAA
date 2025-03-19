#include <stdio.h> 
 
#define MOD 1000000009 
 
int countWays(int A, int S) { 
    int dp[A + 1]; 
    for (int i = 0; i <= A; i++) dp[i] = 0; 
    dp[0] = 1; 
     
    for (int i = S; i <= A; i++) { 
        for (int j = i; j <= A; j++) { 
            dp[j] = (dp[j] + dp[j - i]) % MOD; 
        } 
    } 
    return dp[A]; 
} 
 
int main() { 
    int t, A, S; 
    scanf("%d", &t); 
     
    while(t--) { 
        scanf("%d %d", &A, &S); 
        printf("%d\n", countWays(A, S)); 
    } 
    return 0; 
}