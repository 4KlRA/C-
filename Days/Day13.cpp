#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
void factors(int n){
    vector<int> factors;
    for (int i = 1; i * i <= n; i++){
    if (n % i == 0){
        factors.push_back(i);
        if(i != n/i)
            factors.push_back(n/i);
    }
}
    cout << "Factors of " << n << ": ";
    for (int factor : factors){
        cout << factor << " ";
    }
    cout << "\n";
}

int countSubarraysWithSumK(const vector<int>& arr, int k){
    int count = 0;
    for (size_t i = 0; i < arr.size(); i++){
        int sum = 0;
        for (size_t j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int main(){
    // Check prime using optimized method (√n)
    cout << "Enter a number to check if it's prime: ";
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << n << " is a prime number.\n";
    } else {
        cout << n << " is not a prime number.\n";
    }
    // Find all factors of a number
    cout << "Enter a number to find its factors: ";
    cin >> n;
    factors(n);
    // Count subarrays with sum = k (basic version)
    cout << "Enter the size of the array and the target sum (k): ";
    int size, k;
    cin >> size >> k;
    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int result = countSubarraysWithSumK(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << "\n";
    return 0;
}