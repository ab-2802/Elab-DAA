#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
void dfs(int i, vector<vector<char>> &c, vector<int> &g, int x) { 
g[i] = x; 
for (int j = 0, n = g.size(); j < n; j++) 
if (c[i][j] == 'Y' && g[j] < 0) dfs(j, c, g, x); 
} 
void solve(int idx) { 
int k, x = 0; 
cin >> k; 
vector<int> p(k), g(k, -1), id(k), gr[k]; 
for (int &y : p) cin >> y; 
vector<vector<char>> c(k, vector<char>(k)); 
for (auto &r : c) cin >> r.data(); 
for (int i = 0; i < k; i++) if (g[i] < 0) dfs(i, c, g, x++); 
for (int i = 0; i < k; gr[g[i]].push_back(p[i]), i++); 
for (auto &x : gr) sort(x.begin(), x.end()); 
for (int i = 0; i < k; cout << gr[g[i]][id[g[i]]++] << " ", i++); 
} 
int main() { 
ios::sync_with_stdio(0); 
cin.tie(0); 
solve(0); 
}