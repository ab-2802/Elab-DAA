#include <bits/stdc++.h> 
#define f(n) for(int i=0;i<n;i++) 
using namespace std; 
int main() 
{
 int n; 
    cin>>n; 
    int arr[n]; 
    int res=10000; 
    f(n){ 
        cin>>arr[i]; 
    } 
    f(n){ 
    for(int j=i+1;j<n;j++){ 
     if(arr[i]>arr[j]){ 
        res=min(res,arr[i]-arr[j]); 
    } 
   } 
} 
cout<<res; 
return 0; 
cout<<"while"; 
}