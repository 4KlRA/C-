#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

string reverseWords(const string& str) {
    string result;
    vector <string> words;
    string word;
    for (char ch : str) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) {
            result += ' ';
        }
    }
    return result;
}

int main() {
    // Check if number is power of 2
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPowerOfTwo(n)) {
        cout << n << " is a power of 2." << endl;
    } else {
        cout << n << " is not a power of 2." << endl;
    }

    // Reverse words in a sentence
    string s;
    cout << "Enter a sentence: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Original: " << s << endl;
    cout << "Reversed: " << reverseWords(s) << endl;
    return 0;
}