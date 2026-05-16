#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int num, count = 0;
    for(auto& x : nums) {
        if(count == 0) num = x;
        count += (x == num ? 1 : -1);
        }
    count = 0;
    for(auto& x : nums) {
        if(x == num) count++;
    }
    if (count > n/2) return num;
    return -1;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0, count = 0;
    for(const auto& num : numSet) {
        if(numSet.count(num - 1) == 0) {
            int current = num;
            count = 1;
            while(numSet.count(current + 1)) {
                current++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

void merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& mergedArr) {
    int i = 0, j = 0, k = 0;
    int leftSize = leftArr.size(), rightSize = rightArr.size();
    while(i < leftSize && j < rightSize) {
        if(leftArr[i] <= rightArr[j]) {
            mergedArr[k++] = leftArr[i++];
        } else {
            mergedArr[k++] = rightArr[j++];
        }
    }
    while(i < leftSize) {
        mergedArr[k++] = leftArr[i++];
    }
    while(j < rightSize) {
        mergedArr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int>& arr) {
    if(arr.size() <= 1) return;
    int mid = arr.size() / 2;
    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());
    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, arr);
}

int main() {
    // Find majority element using Boyer-Moore approach
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];
    int result = majorityElement(nums);
    if(result != -1) {
        cout << "Majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    // Find longest consecutive sequence (basic version)
    int longest = longestConsecutive(nums);
    cout << "Length of longest consecutive sequence is: " << longest << endl;

    // Implement merge sort
    mergeSort(nums);
    cout << "Array after merge sort: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}