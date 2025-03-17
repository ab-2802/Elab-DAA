#include <iostream>
using namespace std;

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;

    int count = 0;

    while(p<=s) { 
        s -= p;
        count++; 
        p = max(m, p - d); 
    }

    cout << count << endl; 
    return 0;
}