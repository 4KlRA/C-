#include <iostream> 
#include <vector>
using namespace std;

void rotateArray(vector<int>& arr, int n, int k){
    k = k % n; // Handle cases where k >= n
    vector<int> temp(k);

    // Store the last k elements in a temporary array
    for (int i = 0; i < k; i++){
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--){
        arr[i] = arr[i - k];
    }

    // Copy the temporary array back to the original array
    for (int i = 0; i < k; i++){
        arr[i] = temp[i];
    }
}

bool isBalancedParentheses(const string& str){
    vector<char> stack;
    for (char ch : str){
        if (ch == '(' || ch == '{' || ch == '['){
            stack.push_back(ch);
        } else {
            if (stack.empty()){
                return false;
            }
            char top = stack.back();
            stack.pop_back();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')){
                return false;
            }
        }
    }
    return stack.empty();
}

char firstNonRepeatingCharacter(const string& str){
    vector<int> count(256, 0); // Assuming ASCII character set
    for (char ch : str){
        count[ch]++;
    }
    for (char ch : str){
        if (count[ch] == 1){
            return ch;
        }
    }
    return '\0'; // Return null character if no non-repeating character is found
}

int main(){
    // Rotate array by k positions
    cout << "Enter the size of the array and the number of positions to rotate: ";
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rotateArray(arr, n, k);
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Check balanced parentheses
    cout << "Enter a string of parentheses: ";
    string parentheses;    
    cin >> parentheses;
    if (isBalancedParentheses(parentheses)){
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    // Find first non-repeating character in string
    cout << "Enter a string to find the first non-repeating character: ";
    string input;
    cin >> input;
    char result = firstNonRepeatingCharacter(input);
    if (result != '\0'){
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }
    return 0;
}