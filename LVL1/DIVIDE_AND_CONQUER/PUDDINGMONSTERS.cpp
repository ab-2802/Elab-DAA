#include <bits/stdc++.h>
#define fi first se second
#define lo long long
#define inf 1000000009
#define md 1000000007
#define li 300005
#define mp make_pair
#define pb push_back
using namespace std;
int n, x, y, v[li], a[li], b[li], mn[li], mx[li], g[li];
lo ans;
void work(int *a,int *b) {
    int n = a[0], m = b[0]; 
    mn[m + 1] = inf; 
    for (int i = 1; i <= m; i++) {
        mn[i] = min(mn[i - 1], b[i]);
        mx[i] = max(mx[i - 1], b[i]);}
    int mna = inf, mxa = 0;
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        mna = min(mna, a[i]);
        mxa = max(mxa, a[i]);
        int d = mxa - mna + 1 - i;
        if (d > 0 && d <= m && mn[d] > mna && mx[d] < mxa) 
            ans++;
        for (; r <= m && mn[r] > mna; r++) 
            g[mx[r] - r]++;
        for (; l < r && mx[l] < mxa; l++) 
            g[mx[l] - l]--;
        ans += g[mna + i - 1]; }
    for (int i = l; i < r; i++) 
        g[mx[i] - i] = 0;}
void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    a[0] = mid - l + 1;
    b[0] = r - mid;
    for (int i = l; i <= mid; i++) 
        a[mid + 1 - i] = v[i];
    for (int i = mid + 1; i <= r; i++) 
        b[i - mid] = v[i];
    work(a, b);
    work(b, a);
    solve(l, mid);
    solve(mid + 1, r);}
int main() {
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>x>>y;
        v[x] = y;}
    mn[0] = inf;
    solve(1, n);
    printf("%lld\n", ans + n);
    return 0;}