#include <iostream>
#include <string>
using namespace std;

void findPrimesInRange (int start, int end) {
    for (int num = start; num <= end; num++) {
        if(num < 2) continue;
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool areRotations(const string &str1, const string &str2) {
    if (str1.length() != str2.length()) return false;
    string temp = str1 + str1;
    return temp.find(str2) != string::npos;
}

int main() {
    // Find prime numbers in a range (optimized)
    cout << "Enter the start and end of the range to search for primes: ";
    int start, end;
    cin >> start >> end;

    cout << "Prime numbers in the range [" << start << ", " << end << "]: ";
    findPrimesInRange(start, end);
    cout << endl;

    // Find LCM using GCD method
    cout << "Enter two numbers to find their LCM: ";
    int x, y;
    cin >> x >> y;
    cout << "LCM of " << x << " and " << y << " is: " << lcm(x, y) << endl;

    // Check if two strings are rotations of each other
    cout << "Enter two strings to check if they are rotations of each other: ";
    string s1, s2;
    cin >> s1 >> s2;
    if (areRotations(s1, s2)) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are not rotations of each other." << endl;
    }   
}