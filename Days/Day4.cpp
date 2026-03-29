#include <iostream>
using namespace std;

int main(){
    // Check if a number is perfect number
    //Print all divisors of a number
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
            cout << i << " ";
        }
    }
    cout << endl;

    if(sum == n)
        cout << "Perfect number" << endl;
    else
        cout << "Not a perfect number" << endl;

    //Count even and odd elements in array
    //Find smallest element in array
    int size, evenCount = 0, oddCount = 0, smallest;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
        if(arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }   
    }
    cout << "Even elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;
    smallest = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    cout << "Smallest element: " << smallest << endl;

    //Swap two numbers without third variable
    int a, b;
    cout << "Enter two numbers to swap: ";
    cin >> a >> b;
    cout << "Before swapping: " << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swapping: " << a << " " << b << endl;

    return 0;

}