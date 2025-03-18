#include <iostream>
using namespace std;

string willMonkeysMeet(int s1, int r1, int s2, int r2) {
    if (r1 == r2) {
        // If rates are the same, they will only meet if they start at the same position
        return (s1 == s2) ? "YES" : "NO";
    }

    // Calculate the time t when they meet
    int numerator = s1 - s2;
    int denominator = r2 - r1;

    // Check if t is a non-negative integer
    if (numerator % denominator == 0 && numerator / denominator >= 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int s1, r1, s2, r2;
    cin >> s1 >> r1 >> s2 >> r2;

    string result = willMonkeysMeet(s1, r1, s2, r2);

    // Use a for loop and break for demonstration
    for (int i = 0; i < 1; i++) {
        cout << result << endl;
        break; // Exit the loop after printing once
    }

    return 0;
}