#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
void c(){ 
    int x; 
    cin>>x; 
} 
int main() { 
    int n, k; 
    cin>>n>>k; 
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
    int limit = (1 << k); // 2^k 
    vector<int> result(limit); 
    for (int x = 0; x < limit; x++) { 
        int min_val = INT_MAX; 
        for (int i = 0; i < n; i++) { 
            for (int j = i + 1; j < n; j++) { 
                min_val = min(min_val, abs((arr[i] ^ x) - (arr[j] ^ x))); 
} 
} 
result[x] = min_val; 
} 
for (int x = 0; x < limit; x++) { 
cout << result[x] << " "; 
} 
cout << endl; 
return 0; 
}