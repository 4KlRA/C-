#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cctype>
using namespace std;

vector<int> arr;

void topMenu(){
    cout << "Menu Driven System" << endl;
    cout << "Select an option:" << endl;
    cout << "1. Calculator" << endl;
    cout << "2. Array Operations" << endl;
    cout << "3. String Operations" << endl;
    cout << "4. Number Operations" << endl;
    cout << "5. Pattern Printing" << endl;
    cout << "7. Exit" << endl;
}

void calculator(int &choice){
    switch(choice){
        case 1:
            cout << "Enter two numbers: ";
            double a, b;
            cin >> a >> b;
            cout << "Result: " << a + b << endl;
            break;
        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a - b << endl;
            break;
        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a * b << endl;
            break;
        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if(b != 0)
                cout << "Result: " << a / b << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        case 5:
            cout << "Enter two integers: ";
            int x, y;
            cin >> x >> y;
            if(y != 0)
                cout << "Result: " << x % y << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        case 6:
            // Back to main menu
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void calculatorMenu(){
    cout << "Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Back" << endl;
    int choice;
    cin >> choice;
    calculator(choice);
}

void arrayOperations(int &choice){
    switch(choice){
        case 1:
            // Input Array
            int n;
            cout << "Enter size of array: ";
            cin >> n;
            arr.resize(n);
            cout << "Enter elements of array: ";
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            break;
        case 2:
            // Display Array
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            break;
        case 3:
            // Find Maximum
            if(arr.empty()){
                cout << "Array is empty!" << endl;
            } else {
                int maxElement = *max_element(arr.begin(), arr.end());                    
                cout << "Maximum element: " << maxElement << endl;
            }
            break;
        case 4:
            // Find Minimum
            if(arr.empty()){
                cout << "Array is empty!" << endl;
            } else {
                int minElement = *min_element(arr.begin(), arr.end());
                cout << "Minimum element: " << minElement << endl;
            }
            break;
        case 5:
            // Search Element
            int element;
            cout << "Enter element to search: ";
            cin >> element;
            auto it = find(arr.begin(), arr.end(), element);
            if(it != arr.end()){
                cout << "Element found at index: " << distance(arr.begin(), it) << endl;
            } else {
                cout << "Element not found!" << endl;
            }
            break;
        case 6:
            // Sort Array
            sort(arr.begin(), arr.end());
            cout << "Array sorted!" << endl;
            break;
        case 7:
            // Sum of Elements
            int sum = accumulate(arr.begin(), arr.end(), 0);
            cout << "Sum of elements: " << sum << endl;
            break;
        case 8:
            // Back to main menu
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    
}

void arrayOperationsMenu(){
    cout << "Array Operations Menu:" << endl;
    cout << "1. Input Array" << endl;
    cout << "2. Display Array" << endl;
    cout << "3. Find Maximum" << endl;
    cout << "4. Find Minimum" << endl;
    cout << "5. Search Element" << endl;
    cout << "6. Sort Array" << endl;
    cout << "7. Sum of Elements" << endl;
    cout << "8. Back" << endl;
    int choice;
    cin >> choice;
    arrayOperations(choice);
}

void stringOperations(int &choice){
    switch(choice){
        case 1:
            // Length of String
            string str;
            cout << "Enter a string: ";
            cin >> str;
            cout << "Length of string: " << str.length() << endl;
            break;
        case 2:
            // Reverse String
            cout << "Enter a string: ";
            cin >> str;
            reverse(str.begin(), str.end());
            cout << "Reversed string: " << str << endl;
            break;
        case 3:
            // Palindrome Check
            cout << "Enter a string: ";
            cin >> str;
            string reversedStr = str;
            reverse(reversedStr.begin(), reversedStr.end());
            if(str == reversedStr){
                cout << "The string is a palindrome." << endl;
            } else {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        case 4:
            // Count Vowels & Consonants
            cout << "Enter a string: ";
            cin >> str;
            int vowels = 0, consonants = 0;
            for(char c : str){
                if(isalpha(c)){
                    char lowerC = tolower(c);
                    if(lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u'){
                        vowels++;
                    } else {
                        consonants++;
                    }
                }
            }
            cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
            break;
        case 5:
            // Convert Case (upper/lower)
            cout << "Enter a string: ";
            cin >> str;
            for(char &c : str){
                if(islower(c)){
                    c = toupper(c);
                } else if(isupper(c)){
                    c = tolower(c);
                }
            }
            cout << "Converted string: " << str << endl;
            break;
        case 6:
            // Back to main menu
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void stringOperationsMenu(){
    cout << "String Operations Menu:" << endl;
    cout << "1. Length of String" << endl;
    cout << "2. Reverse String" << endl;
    cout << "3. Palindrome Check" << endl;
    cout << "4. Count Vowels & Consonants" << endl;
    cout << "5. Convert Case (upper/lower)" << endl;
    cout << "6. Back" << endl;
    int choice;
    cin >> choice;
    stringOperations(choice);
}

void numberOperations(int &choice){
    switch(choice){
        case 1:
            // Check Prime
            int num;
            cout << "Enter a number: ";
            cin >> num;
            if(num <= 1){
                cout << "Not a prime number." << endl;
                break;
            }
            bool isPrime = true;
            for(int i = 2; i*i <= num; i++){
                if(num % i == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                cout << "The number is prime." << endl;
            } else {
                cout << "The number is not prime." << endl;
            }
            break;
        case 2:
            // Factorial
            cout << "Enter a number: ";
            cin >> num;
            unsigned long long factorial = 1;
            for(int i = 1; i <= num; i++){
                factorial *= i;
            }
            cout << "Factorial: " << factorial << endl;
            break;
        case 3:
            // Fibonacci Series
            int n, t1 = 0, t2 = 1, nextTerm = 0;
            cout << "Enter the number of terms: ";
            cin >> n;
            cout << "Fibonacci Series: ";
            for(int i = 1; i <= n; i++){
                cout << t1 << " ";
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
            }
            cout << endl;
            break;
        case 4:
            // Armstrong Number
            int originalNum, sum = 0, digits = 0, remainder, tempNum;
            cout << "Enter a number: ";
            cin >> num;
            originalNum = num;
            tempNum = num;

            while(tempNum != 0){
                tempNum /= 10;
                digits++;
            }

            tempNum = num;

            while(tempNum != 0){
                remainder = tempNum % 10;
                sum += pow(remainder, digits);
                tempNum /= 10;
            }

            if(sum == originalNum){
                cout << "The number is an Armstrong number." << endl;
            } else {
                cout << "The number is not an Armstrong number." << endl;
            }
            break;
        case 5:
            // Perfect Number
            cout << "Enter a number: ";
            cin >> num;
            int sum = 0;
            for(int i = 1; i < num; i++){
                if(num % i == 0){
                    sum += i;
                }
            }
            if(sum == num){
                cout << "The number is a perfect number." << endl;
            } else {
                cout << "The number is not a perfect number." << endl;
            }
            break;
        case 6:
            // Back to main menu
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void numberOperationsMenu(){
    cout << "Number Operations Menu:" << endl;
    cout << "1. Check Prime" << endl;
    cout << "2. Factorial" << endl;
    cout << "3. Fibonacci Series" << endl;
    cout << "4. Armstrong Number" << endl;
    cout << "5. Perfect Number" << endl;
    cout << "6. Back" << endl;
    int choice;
    cin >> choice;
    numberOperations(choice);
}

void patternPrinting(int &choice){
    switch(choice){
        case 1:
            // Star Triangle
            int n;
            cout << "Enter the number of rows: ";
            cin >> n;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                    cout << "* ";
                }
                cout << endl;
            }
            break;
        case 2:
            // Inverted Triangle
            cout << "Enter the number of rows: ";
            cin >> n;
            for(int i = n; i >= 1; i--){
                for(int j = 1; j <= i; j++){
                    cout << "* ";
                }
                cout << endl;
            }
            break;
        case 3:
            // Pyramid
            cout << "Enter the number of rows: ";
            cin >> n;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n - i; j++){
                    cout << "  ";
                }
                for(int k = 1; k <= 2 * i - 1; k++){
                    cout << "* ";
                }
                cout << endl;
            }
            break;
        case 4:
            // Number Patterns
            cout << "Enter the number of rows: ";
            cin >> n;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                    cout << j << " ";
                }
                cout << endl;
            }
            break;
        case 5:
            // Back to main menu
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void patternPrintingMenu(){
    cout << "Pattern Printing Menu:" << endl;
    cout << "1. Star Triangle" << endl;
    cout << "2. Inverted Triangle" << endl;
    cout << "3. Pyramid" << endl;
    cout << "4. Number Patterns" << endl;
    cout << "5. Back" << endl;
    int choice;
    cin >> choice;
    patternPrinting(choice);
}

void fileHandlingMenu(){
    //Future Project Update
}

int main(){
    int choice;
    do {
        // show menu
        topMenu();
        // take choice
        cin >> choice;
        // switch case
        switch(choice){
            case 1:
                calculatorMenu();
                break;
            case 2:
                arrayOperationsMenu();
                break;
            case 3:
                stringOperationsMenu();
                break;
            case 4:
                numberOperationsMenu();
                break;
            case 5:
                patternPrintingMenu();
                break;
            case 6:
                fileHandlingMenu();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 7);
}