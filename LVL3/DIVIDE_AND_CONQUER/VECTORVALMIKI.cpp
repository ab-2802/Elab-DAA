#include <bits/stdc++.h> 
using namespace std; 
using ll = long long; 
ll gcd(ll a, ll b) { 
return b == 0 ? a : gcd(b, a % b); 
} 
ll lcm(ll a, ll b) { 
return (a / gcd(a, b)) * b; 
} 
void reduceFraction(ll &num, ll &den) { 
ll g = gcd(num, den); 
num /= g; 
den /= g; 
} 
int main() { 
ll t, w, b; 
cin>>t>>w>>b; 
ll l = lcm(w, b); 
ll count = t / l; 
ll num = min(w, b) * count + min(t % l, min(w, b) - 1); 
ll den = t; 
reduceFraction(num, den); 
cout << num << "/" << den << endl; 
return 0; 
} 
void t(){ 
cout<<"int tie(int a,int b)"; 
}