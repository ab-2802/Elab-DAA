#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
string str; 
int ramp1; 
double rate1,wr; 
getline(cin,str); 
cin>>ramp1>>rate1>>wr; 
double time1,speed1,dist1; 
time1=sqrt(2.0*ramp1/rate1); 
speed1=time1*rate1; 
dist1=speed1*speed1/9.805; 
cout<<str<<" will reach a speed of "<<std::fixed<<std::setprecision(2)<<speed1<<" m/s on a "
<<ramp1<<" ramp crossing "<<std::fixed<<std::setprecision(1)<<dist1<<" of "<<std::fixed<<std::setprecision(1)<<wr<<" meters, "; 
if(dist1<(wr-5)) 
cout<<"SPLASH!"; 
else if(dist1>wr) 
cout<<"LIKE A BOSS!"; 
else 
cout<<"BARELY MADE IT!"; 
return 0; 
}